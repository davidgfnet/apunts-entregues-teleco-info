#header
<<
#include <string>
#include <iostream>
using namespace std;

// struct to store information about tokens
typedef struct {
  string kind;
  string text;
} Attrib;

// function to fill token information (predeclaration)
void zzcr_attr(Attrib *attr, int type, char *text);

// fields for AST nodes
#define AST_FIELDS string kind; string text;
#include "ast.h"

// macro to create a new AST node (and function predeclaration)
#define zzcr_ast(as,attr,ttype,textt) as=createASTnode(attr,ttype,textt)
AST* createASTnode(Attrib* attr, int ttype, char *textt);
>>

<<
#include <cstdlib>
#include <cmath>
// function to fill token information
void zzcr_attr(Attrib *attr, int type, char *text) {
  if (type == NUM) {
    attr->kind = "intconst";
    attr->text = text;
  }
  else if (type == IDENT) {
    attr->kind = "identificator";
    attr->text = text;
  }
  else {
    attr->kind = text;
    attr->text = "";
  }
}

// function to create a new AST node
AST* createASTnode(Attrib* attr, int type, char* text) {
  AST* as = new AST;
  as->kind = attr->kind; 
  as->text = attr->text;
  as->right = NULL; 
  as->down = NULL;
  return as;
}

/// get nth child of a tree. Count starts at 0.
/// if no such child, returns NULL
AST* child(AST *a,int n) {
 AST *c=a->down;
 for (int i=0; c!=NULL && i<n; i++) c=c->right;
 return c;
} 

/// print AST, recursively, with indentation
void ASTPrintIndent(AST *a,string s)
{
  if (a==NULL) return;

  cout<<a->kind;
  if (a->text!="") cout<<"("<<a->text<<")";
  cout<<endl;

  AST *i = a->down;
  while (i!=NULL && i->right!=NULL) {
    cout<<s+"  \\__";
    ASTPrintIndent(i,s+"  |"+string(i->kind.size()+i->text.size(),' '));
    i=i->right;
  }
  
  if (i!=NULL) {
      cout<<s+"  \\__";
      ASTPrintIndent(i,s+"   "+string(i->kind.size()+i->text.size(),' '));
      i=i->right;
  }
}

/// print AST 
void ASTPrint(AST *a)
{
  while (a!=NULL) {
    cout<<" ";
    ASTPrintIndent(a,"");
    a=a->right;
  }
}

int dictionary[(int)('Z'-'A')+1] = {0};

void execute_program(AST * a);

int evaluate(AST* a) {
	if (a == NULL) return 0;
	else if (a->kind == "intconst")
		return atoi(a->text.c_str());
	else if (a->kind == "+")
		return evaluate(child(a,0)) + evaluate(child(a,1));
	else if (a->kind == "-")
		return evaluate(child(a,0)) - evaluate(child(a,1));
	else if (a->kind == "*")
		return evaluate(child(a,0)) * evaluate(child(a,1));
	else if (a->kind == "/")
		return evaluate(child(a,0)) / evaluate(child(a,1));
	else if (a->kind == "identificator") {
		string ident = a->text;
		return dictionary[(int)(ident[0]-'a')];
	}
}

void execute_instruction(AST * a) {
	if (a == NULL) return;

	if(a->kind == ":=") {
		AST * ide = child(a,0);
		string ident = ide->text;
		if (ide->kind != "identificator" or ident.size() != 1) {
			cout << "Error en el write!!!" << endl;
			return;
		}
		dictionary[(int)(ident[0]-'a')] = evaluate(child(a,1));
	}
	else if(a->kind == "write") {
		AST * ide = child(a,0);
		string ident = ide->text;
		if (ide->kind != "identificator" or ident.size() != 1) {
			cout << "Error en el write!!!" << endl;
			return;
		}
		cout << "Write " << ident[0] << ": " << dictionary[(int)(ident[0]-'a')] << endl;
	}
	else if(a->kind == "if") {
		AST * cond = child(a,0);
		int res = evaluate(cond);
		if (res != 0) {
			execute_program(child(a,1));
		}
	}
	else if(a->kind == "while") {
		AST * cond = child(a,0);
		while (evaluate(cond) != 0) {
			execute_program(child(a,1));
		}
	}

}

void execute_program(AST * a) {
	for (int i=0; a!=NULL; i++) {
		execute_instruction(a);
		a=a->right;
	}
}

int main() {
  AST *root = NULL;
  ANTLR(program(&root), stdin);
  ASTPrint(root);
  execute_program(root);
}
>>

#lexclass START
#token NUM "[0-9]+"
#token PLUS "\+"
#token MINUS "\-"
#token PROD "\*"
#token DIVI "\/"
#token SPACE "[\ \n]" << zzskip();>>
#token OPENPAR "\("
#token CLOSEPAR "\)"
#token WRITE "write"
#token IDENT "[a-z]"
#token ASSIGN ":="
#token IF "if"
#token THEN "then"
#token ENDIF "endif"
#token DO "do"
#token WHILE "while"
#token ENDWHILE "endwhile"

expr:  expr2 ((PLUS^|MINUS^) expr2)*;
expr2: expr3 ((PROD^|DIVI^) expr3)*;
expr3: NUM | IDENT | OPENPAR! expr CLOSEPAR!;

instruction:  WRITE^ IDENT | IDENT ASSIGN^ expr | IF^ expr THEN! (instruction)* ENDIF! | WHILE^ expr DO! (instruction)* ENDWHILE!;
program:      (instruction)*;



