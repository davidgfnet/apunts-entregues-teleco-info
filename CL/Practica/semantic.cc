/* ===== semantic.c ===== */
#include <string>
#include <iostream>
#include <map>
#include <list>
#include <vector>


using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include "ptype.hh"
#include "symtab.hh"

#include "myASTnode.hh"

#include "semantic.hh"

// feedback the main program with our error status
int TypeError = 0;


/// ---------- Error reporting routines --------------

void errornumparam(int l) {
  TypeError = 1;
  cout<<"L. "<<l<<": The number of parameters in the call do not match."<<endl;
}

void errorincompatibleparam(int l,int n) {
  TypeError = 1;
  cout<<"L. "<<l<<": Parameter "<<n<<" with incompatible types."<<endl;
}

void errorreferenceableparam(int l,int n) {
  TypeError = 1;
  cout<<"L. "<<l<<": Parameter "<<n<<" is expected to be referenceable but it is not."<<endl;
}

void errordeclaredident(int l, string s) {
  TypeError = 1;
  cout<<"L. "<<l<<": Identifier "<<s<<" already declared."<<endl;
}

void errornondeclaredident(int l, string s) {
  TypeError = 1;
  cout<<"L. "<<l<<": Identifier "<<s<<" is undeclared."<<endl;
}

void errornonreferenceableleft(int l, string s) {
  TypeError = 1;
  cout<<"L. "<<l<<": Left expression of assignment is not referenceable."<<endl;
}

void errorincompatibleassignment(int l) {
  TypeError = 1;
  cout<<"L. "<<l<<": Assignment with incompatible types."<<endl;
}

void errorbooleanrequired(int l,string s) {
  TypeError = 1;
  cout<<"L. "<<l<<": Instruction "<<s<<" requires a boolean condition."<<endl;
}

void errorisnotprocedure(int l) {
  TypeError = 1;
  cout<<"L. "<<l<<": Operator ( must be applied to a procedure in an instruction."<<endl;
}

void errorisnotfunction(int l) {
  TypeError = 1;
  cout<<"L. "<<l<<": Operator ( must be applied to a function in an expression."<<endl;
}

void errorincompatibleoperator(int l, string s) {
  TypeError = 1;
  cout<<"L. "<<l<<": Operator "<<s<<" with incompatible types."<<endl;
}

void errorincompatiblereturn(int l) {
  TypeError = 1;
  cout<<"L. "<<l<<": Return with incompatible type."<<endl;
}

void errorreadwriterequirebasic(int l, string s) {
  TypeError = 1;
  cout<<"L. "<<l<<": Basic type required in "<<s<<"."<<endl;
}

void errornonreferenceableexpression(int l, string s) {
  TypeError = 1;
  cout<<"L. "<<l<<": Referenceable expression required in "<<s<<"."<<endl;
}

void errornonfielddefined(int l, string s) {
  TypeError = 1;
  cout<<"L. "<<l<<": Field "<<s<<" is not defined in the struct."<<endl;
}

void errorfielddefined(int l, string s) {
  TypeError = 1;
  cout<<"L. "<<l<<": Field "<<s<<" already defined in the struct."<<endl;
}

void errorexpectedintconst(int l) {
  TypeError = 1;
  cout<<"L. "<<l<<": Expected a positive integer constant for the array dimension."<<endl;
}


/// ------------------------------------------------------------
/// Table to store information about program identifiers
symtab symboltable;

static void InsertintoST(int line,string kind,string id,ptype tp)
{
  infosym p;

  if (symboltable.find(id) && symboltable.jumped_scopes(id)==0) errordeclaredident(line,id);
  else {
    symboltable.createsymbol(id);
    symboltable[id].kind=kind;
    symboltable[id].tp=tp;
  }
}

/// ------------------------------------------------------------

bool isbasickind(string kind) {
  return kind=="int" || kind=="bool" || kind=="string";
}


// Proc/func parameter checking
void check_params(AST *a,ptype tp,int line) {

  ptype curparam = tp;         // Parameter list
  AST * curexpr = a;  // Expressions for parameter filling

  // First of all check the num of params (and skip the paramcheck if it fails)
  {
    ptype curparam2 = curparam;
    AST * curexpr2 = curexpr;
    while (curparam2 != 0 && curexpr2 != 0) {
      curparam2 = curparam2->right;
      curexpr2 = curexpr2->right;
    }
    if (curparam2 != 0 || curexpr2 != 0) {
      errornumparam(line);
      return;
    }
  }

  int paramcounter = 1;
  while (curparam != 0 && curexpr != 0) {
    ptype paramtype = curparam->down;

    // Check the param expression
    TypeCheck(curexpr);

    // Check ref params
    if (curparam->kind == "ref" && curexpr->ref == 0) {
      errorreferenceableparam(curexpr->line,paramcounter);
    }

    // Check param type
    if (!equivalent_types(curexpr->tp,paramtype) and
        curexpr->tp->kind != "error" ) {
      errorincompatibleparam(curexpr->line,paramcounter);
    }

    curparam = curparam->right;
    curexpr = curexpr->right;
    paramcounter++;
  }
}

void insert_vars(AST *a)
{
  if (!a) return;
  TypeCheck(child(a,0));
  InsertintoST(a->line,"idvarlocal",a->text,child(a,0)->tp);
  insert_vars(a->right); 
}

void insert_args(AST *a)
{
  if (!a) return;
  TypeCheck(child(a,1));
  if (a->kind == "val") {
    InsertintoST(a->line,"idparval",child(a,0)->text,child(a,1)->tp);
  }else{
    InsertintoST(a->line,"idparref",child(a,0)->text,child(a,1)->tp);
  }
  insert_args(a->right); 
}


void construct_struct(AST *a)
{
  AST *a1=child(a,0);
  a->tp=create_type("struct",0,0);

  while (a1!=0) {
    TypeCheck(child(a1,0));
    if (a->tp->struct_field.find(a1->text)==a->tp->struct_field.end()) {
      a->tp->struct_field[a1->text]=child(a1,0)->tp;
      a->tp->ids.push_back(a1->text);
     } else {
      errorfielddefined(a1->line,a1->text);
    }
    a1=a1->right;
  }
}

void construct_array(AST *a)
{
  a->tp=create_type("array",0,0);

  AST * numelements = child(a,0);
  AST * typeelements = child(a,1);

  // Check the type of the integer which indicates the array size
  TypeCheck(numelements);
  if (numelements->kind != "error") {
    if (numelements->kind != "intconst" or atoi(numelements->text.c_str()) == 0) {
      // FIXME errorexpectedintconst(numelements->line);  // CAL????
    }
  }

  // Check the type of the array
  TypeCheck(typeelements);

  // Dimension the array and save the type at down
  a->tp->numelemsarray = atoi(numelements->text.c_str()); // Evaluate num elem
  a->tp->down = typeelements->tp;
}


void create_header(AST *a)
{
  //...
}


void insert_header(AST *a) {
  // Insert the function name as a symbol!!!
  a->tp = create_type(a->kind,0,0);
  InsertintoST(a->line,a->kind,child(a,0)->text,a->tp);

  // Check the types of the parameters and add to the list 
  // (a->tp->down points to the first element of a list (linked by right)
  AST * param = child(child(child(a,0),0),0);
  while (param != 0) {
    // Check the param type
    TypeCheck(child(param,1));

    // Now add the type to the parameter list
    ptype paramtype = create_type(param->kind,0,0);
    paramtype->down = child(param,1)->tp;

    list_add_right_tail(a->tp, paramtype);

    param = param->right;
  }

  if (a->kind == "function") {
    // Get the return type and put i a->tp->right
    AST * rettype = child(child(a,0),1);
    TypeCheck(rettype);
    a->tp->right = rettype->tp;
  }
}

void insert_headers(AST *a)
{
  while (a!=0) {
    insert_header(a);
    a=a->right;
  }
}

void TypeCheck(AST *a,string info)
{
  if (!a) {
    return;
  }

  if (a->kind=="program") {
    a->sc=symboltable.push();
    insert_vars(child(child(a,0),0));
    insert_headers(child(child(a,1),0));

    // Check proc/func
    TypeCheck(child(a,1));
    // Check instructions
    TypeCheck(child(a,2),"instruction");

    symboltable.pop();
  }
  else if (a->kind=="if" || a->kind=="while") {
    // The first child is expression condition, which must evaluate to bool
    // Second and third are the oneor two instructions blocks
    TypeCheck(child(a,0));
    if (child(a,0)->tp->kind != "error" && child(a,0)->tp->kind != "bool") {
      errorbooleanrequired(child(a,0)->line,a->kind);
    }

    TypeCheck(child(a,1),info);
    TypeCheck(child(a,2),info);  // type lists (maybe null ptr)
  }
  else if (a->kind=="list") {
    // At this point only instruction, procedures or parameters lists are possible.
    for (AST *a1=a->down;a1!=0;a1=a1->right) {
      TypeCheck(a1,info);
    }
  } 
  else if (a->kind=="ident") {
    if (!symboltable.find(a->text)) {
      errornondeclaredident(a->line, a->text);
    } 
    else {
      a->tp=symboltable[a->text].tp;
      if (a->tp->kind != "procedure" and a->tp->kind != "function") {
        a->ref=1;
      }else{
        a->ref=0;
      }
    }
  } 
  else if (a->kind=="function" or a->kind=="procedure") {
    // Setup symbol table
    a->sc=symboltable.push();

    // Insert the headers: arg vars, local vars and func/proc definitions
    insert_args(child(child(child(a,0),0),0));
    insert_vars(child(child(a,1),0));
    insert_headers(child(child(a,2),0));

    // Recursively check the procedure/functions defs
    TypeCheck(child(a,2));

    // Now check all the instructions
    TypeCheck(child(a,3),"instruction");

    if (a->kind=="function") {
      // Check the return expression and if it matches the type
      TypeCheck(child(a,4));
      if (!equivalent_types(child(a,4)->tp,child(child(a,0),1)->tp)) {
        errorincompatiblereturn(child(a,4)->line);
      }
    }

    symboltable.pop();
  }
  else if (a->kind=="ref" || a->kind == "val") {
    // kind: ref/val text: identificator name type: type declared
    TypeCheck(child(a,1));
    a->tp = child(a,1)->tp;
    a->text = child(a,0)->text;
  }
  else if (a->kind=="struct") {
    construct_struct(a);
  }
  else if (a->kind=="array") {
    construct_array(a);
  }
  else if (a->kind==":=") {
    TypeCheck(child(a,0));
    TypeCheck(child(a,1));
    if (!child(a,0)->ref) {
      errornonreferenceableleft(a->line,child(a,0)->text);
    }
    else if (child(a,0)->tp->kind!="error" && child(a,1)->tp->kind!="error" and 
	     !equivalent_types(child(a,0)->tp,child(a,1)->tp)) {
      errorincompatibleassignment(a->line);
    } 
    else {
      a->tp=child(a,0)->tp;
    }
  } 
  else if (a->kind=="intconst") {
    a->tp=create_type("int",0,0);
  } 
  else if (a->kind=="string") {
    a->tp=create_type("string",0,0);
  } 
  else if (a->kind=="true" || a->kind=="false") {
    a->tp=create_type("bool",0,0);
  } 
  else if (a->kind=="+" || (a->kind=="-" && child(a,1)!=0) || a->kind=="*" || a->kind=="/") {
    TypeCheck(child(a,0));
    TypeCheck(child(a,1));

    if ( (child(a,0)->tp->kind != "error" and child(a,0)->tp->kind != "int") or
         (child(a,1)->tp->kind != "error" and child(a,1)->tp->kind != "int") )
      errorincompatibleoperator(a->line,a->kind);

    a->tp=create_type("int",0,0);
  }

  else if (a->kind=="<" || a->kind==">") {
    TypeCheck(child(a,0));
    TypeCheck(child(a,1));

    if ( (child(a,0)->tp->kind != "error" and child(a,0)->tp->kind != "int") or
         (child(a,1)->tp->kind != "error" and child(a,1)->tp->kind != "int") )
      errorincompatibleoperator(a->line,a->kind);

    a->tp=create_type("bool",0,0);
  }
  else if (a->kind=="=") {
    TypeCheck(child(a,0));
    TypeCheck(child(a,1));

    if ((child(a,0)->tp->kind!="error" and (child(a,0)->tp->kind!="int" and child(a,0)->tp->kind!="bool")) or
        (child(a,1)->tp->kind!="error" and (child(a,0)->tp->kind!="int" and child(a,0)->tp->kind!="bool")) or
         child(a,0)->tp->kind != child(a,1)->tp->kind)
      errorincompatibleoperator(a->line,a->kind);

    a->tp=create_type("bool",0,0);
  }

  else if (a->kind=="and" || a->kind=="or") {
    TypeCheck(child(a,0));
    TypeCheck(child(a,1));

    if ( (child(a,0)->tp->kind != "error" and child(a,0)->tp->kind != "bool") or
         (child(a,1)->tp->kind != "error" and child(a,1)->tp->kind != "bool") )
      errorincompatibleoperator(a->line,a->kind);

    a->tp=create_type("bool",0,0);
  }

  else if (a->kind=="not") {
    TypeCheck(child(a,0));

    if ((child(a,0)->tp->kind!="error" and child(a,0)->tp->kind!="bool"))
      errorincompatibleoperator(a->line,a->kind);

    a->tp=create_type("bool",0,0);
  }

  else if (a->kind=="-") {  // Unary, the - operator is back
    TypeCheck(child(a,0));

    if ((child(a,0)->tp->kind!="error" and child(a,0)->tp->kind!="int"))
      errorincompatibleoperator(a->line,a->kind);

    a->tp=create_type("int",0,0);
  }

  else if (isbasickind(a->kind)) {
    a->tp=create_type(a->kind,0,0);
  }
  else if (a->kind=="writeln") {
    TypeCheck(child(a,0));
    if (child(a,0)->tp->kind!="error" && !isbasickind(child(a,0)->tp->kind)) {
      errorreadwriterequirebasic(a->line,a->kind);
    }
  }
  else if (a->kind=="write") {
    TypeCheck(child(a,0));
    if (child(a,0)->tp->kind!="error" && !isbasickind(child(a,0)->tp->kind)) {
      errorreadwriterequirebasic(a->line,a->kind);
    }    
  }
  else if (a->kind=="read") {
    TypeCheck(child(a,0));
    if (child(a,0)->ref == 0) {
      errornonreferenceableexpression(a->line,"read");
    }else{
      if (!isbasickind(child(a,0)->tp->kind)) {
        errorreadwriterequirebasic(a->line,"read");
      }
    }
  }
  else if (a->kind=="[") {
    // Check the type of the field and if it's a reference
    TypeCheck(child(a,0));
    TypeCheck(child(a,1));
    a->ref=child(a,0)->ref;

    if (child(a,0)->tp->kind!="error") {
      if (child(a,0)->tp->kind!="array") {
        errorincompatibleoperator(a->line,"array[]");
      }
      // TODO: Constant array addressing bounding check?
      else {
        a->tp=child(a,0)->tp->down; // The type returned is the type of the array
      }
    }

    if (child(a,1)->tp->kind != "error" and child(a,1)->tp->kind != "int") {
      errorincompatibleoperator(a->line,"[]");
    }
  }
  else if (a->kind=="(") {
  	TypeCheck(child(a,0)); // Check identifier
  	if (child(a,0)->tp->kind!="error") {
      if (symboltable.find(child(a,0)->text)) { // Check for function existance
        if (child(a,0)->tp->kind == "function") { // Function call
          if (info == "instruction")
            errorisnotprocedure(a->line);

          check_params(child(child(a,1),0),symboltable[child(a,0)->text].tp->down,a->line);

          // Return type for functions
          a->tp = child(a,0)->tp->right;
          a->ref = 0;
        }
        else if (child(a,0)->tp->kind == "procedure") {  // Proc call
          if (info != "instruction")
            errorisnotfunction(a->line);

          check_params(child(child(a,1),0),symboltable[child(a,0)->text].tp->down,a->line);
        }
        else {  // Calling on a non func/proc
          if (info == "instruction")
            errorisnotprocedure(a->line);
          else
            errorisnotfunction(a->line);
        }
      }
    }
  }
  else if (a->kind==".") {
    TypeCheck(child(a,0));
    a->ref=child(a,0)->ref;
    if (child(a,0)->tp->kind!="error") {
      if (child(a,0)->tp->kind!="struct") {
        errorincompatibleoperator(a->line,"struct.");
      }
      else if (child(a,0)->tp->struct_field.find(child(a,1)->text)==
	       child(a,0)->tp->struct_field.end()) {
         errornonfielddefined(a->line,child(a,1)->text);
      } 
      else {
         a->tp=child(a,0)->tp->struct_field[child(a,1)->text];
      }
    }
  } 
  else {
    cout<<"BIG PROBLEM! No case defined for kind "<<a->kind<<endl;
  }

  //cout<<"Ending with node \""<<a->kind<<"\""<<endl;
}
