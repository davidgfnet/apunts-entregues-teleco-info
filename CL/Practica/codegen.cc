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
#include "codegest.hh"

#include "myASTnode.hh"

#include "util.hh"
#include "semantic.hh"

#include "codegen.hh"

// symbol table with information about identifiers in the program
// declared in symtab.cc
extern symtab symboltable;

// When dealing with a list of instructions, it contains the maximum auxiliar space
// needed by any of the instructions for keeping non-referenceable non-basic-type values.
int maxoffsetauxspace;

// When dealing with one instruction, it contains the auxiliar space
// needed for keeping non-referenceable values.
int offsetauxspace;

// For distinghishing different labels for different if's and while's.
int newLabelWhile(bool inicialitzar = false){
  static int comptador = 1;
  if (inicialitzar) comptador = 0;
  return comptador++;
}

int newLabelIf(bool inicialitzar = false){
  static int comptador = 1;
  if (inicialitzar) comptador = 0;
  return comptador++;
}


codechain indirections(int jumped_scopes,int t)
{
  codechain c;
  if (jumped_scopes==0) {
    c="aload static_link t"+itostring(t);
  }
  else {
    c="load static_link t"+itostring(t);
    for (int i=1;i<jumped_scopes;i++) {
      c=c||"load t"+itostring(t)+" t"+itostring(t);
    }
  }
  return c;
}

int compute_size(ptype tp)
{
  if (isbasickind(tp->kind)) {
    tp->size=4;
  }
  else if (tp->kind=="array") {
    tp->size=tp->numelemsarray*compute_size(tp->down);
  }
  else if (tp->kind=="struct") {
    tp->size=0;
    for (list<string>::iterator it=tp->ids.begin();it!=tp->ids.end();it++) {
      tp->offset[*it]=tp->size;
      tp->size+=compute_size(tp->struct_field[*it]);
    }
  }
  return tp->size;
}

void gencodevariablesandsetsizes(scope *sc,codesubroutine &cs,bool isfunction=0)
{
  if (isfunction) cs.parameters.push_back("returnvalue");
  for (list<string>::iterator it=sc->ids.begin();it!=sc->ids.end();it++) {
    if (sc->m[*it].kind=="idvarlocal") {
      variable_data vd;
      vd.name="_"+(*it);
      vd.size=compute_size(sc->m[*it].tp);
      cs.localvariables.push_back(vd);
    } else if (sc->m[*it].kind=="idparval" || sc->m[*it].kind=="idparref") {
      compute_size(sc->m[*it].tp);
      cs.parameters.push_back("_"+(*it));
    } else if (sc->m[*it].kind=="idfunc") {
      // Here it is assumed that in tp->right is kept the return value type
      // for the case of functions. If this is not the case you must
      // change this line conveniently in order to force the computation
      // of the size of the type returned by the function.
      compute_size(sc->m[*it].tp->right);
    } else if (sc->m[*it].kind=="idproc") {
      // Nothing to be done.
    }
  }
  cs.parameters.push_back("static_link");
}

codechain GenLeft(AST *a,int t);
codechain GenRight(AST *a,int t);

void CodeGenRealParams(AST *a,ptype tp,codechain &cpushparam,codechain &cremoveparam,int t)
{
  if (!a) return;
  //cout<<"Starting with node \""<<a->kind<<"\""<<endl;

  ptype definicio = symboltable[child(a,0)->text].tp->down;  // Definicio de la funcio
  AST * params = child(child(a,1),0);  // Agafem la llista de parametres que li passem
  while (params != 0) {
    if (definicio->kind == "val") {
      cpushparam=cpushparam||GenRight(params,t)||"pushparam t"+itostring(t);
    }else{
      cpushparam=cpushparam||GenLeft(params,t)||"pushparam t"+itostring(t);
    }
    cremoveparam="killparam"||cremoveparam;
    params = params->right;
    definicio = definicio->right;
  }

  //cout<<"Ending with node \""<<a->kind<<"\""<<endl;
}

codechain GenCall(AST * a, int t) {
  codechain c;
  ptype tipo;
  codechain cpush,cremove;
  CodeGenRealParams(a,tipo,cpush,cremove,t);
  c = cpush||
      indirections(symboltable.jumped_scopes(child(a,0)->text),t)||
      "pushparam t"+itostring(t)||
      "call "+symboltable.idtable(child(a,0)->text)+"_"+child(a,0)->text||
      "killparam"||
      cremove;
  return c;
}

// ...to be completed:
codechain GenLeft(AST *a,int t)
{
  codechain c;

  if (!a) {
    return c;
  }

  //cout<<"Starting with node \""<<a->kind<<"\""<<endl;
  if (a->kind=="ident") {
    // Si passem més d'un scope, cal que fem us del static_link
    if (symboltable.jumped_scopes(a->text) > 0) {
      c = indirections(symboltable.jumped_scopes(a->text),t);
      c=c||"addi t"+itostring(t)+" offset("+symboltable.idtable(a->text)+":_"+a->text+") t"+itostring(t);
    }else{
      if (symboltable[a->text].kind == "idparref") {   //isbasickind(a->tp->kind)))
        c="load _"+a->text+" t"+itostring(t);
      }else{
        c="aload _"+a->text+" t"+itostring(t);
      }
    }
  }
  else if (a->kind=="."){
    c=GenLeft(child(a,0),t)||
      "addi t"+itostring(t)+" "+
      itostring(child(a,0)->tp->offset[child(a,1)->text])+" t"+itostring(t);
  }
  else if (a->kind=="["){
    c=GenLeft(child(a,0),t)||    // Calcul de la base del vector
      GenRight(child(a,1),t+1)||  // Calcul del VALOR del index
      "muli t"+itostring(t+1)+" "+itostring(child(a,0)->tp->down->size)+" t"+itostring(t+1) ||  // Calcul el offset (valor index * tamany tipus)
      "addi t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);  // Suma a la base el offset

  }
  else {
    cout<<"BIG PROBLEM! No case defined for kind "<<a->kind<<endl;
  }
  //cout<<"Ending with node \""<<a->kind<<"\""<<endl;
  return c;
}


// ...to be completed:
codechain GenRight(AST *a,int t)
{
  codechain c;

  if (!a) {
    return c;
  }

  //cout<<"Starting with node \""<<a->kind<<"\""<<endl;
  if (a->ref) {
    if (a->kind=="ident" && symboltable.jumped_scopes(a->text)==0 &&
        isbasickind(symboltable[a->text].tp->kind) && symboltable[a->text].kind!="idparref") {

      // Variable local/per valor al mateix scope, senzill
     	c="load _"+a->text+" t"+itostring(t);
    }
    else if (isbasickind(a->tp->kind)) {
      // Variable a un altre scope, calculem l'adreça (GenLeft) i fem un load per tenir el valor!
      c=GenLeft(a,t)||"load t"+itostring(t)+" t"+itostring(t);

      // En cas de que la variable fos per referencia encara hem de carregar el valor! Nomes per a scope > 0
      if (symboltable[a->text].kind=="idparref" && symboltable.jumped_scopes(a->text)!=0)
        c = c||"load t"+itostring(t)+" t"+itostring(t); 
    }
    else {//...to be done
    }    
  } 
  else if (a->kind=="intconst") {
    c="iload "+a->text+" t"+itostring(t);
  }
  else if (a->kind=="true") {
    c="iload 1 t"+itostring(t);
  }
  else if (a->kind=="false") {
    c="iload 0 t"+itostring(t);
  }
  else if (a->kind=="+") {
    c=GenRight(child(a,0),t)||
      GenRight(child(a,1),t+1)||
      "addi t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);
  }
  else if (a->kind=="-") {
    if (child(a,1) == 0) {  // Unary
      c=GenRight(child(a,0),t)||
        "mini t"+itostring(t)+" t"+itostring(t);
    }
    else {  // Binary
      c=GenRight(child(a,0),t)||
        GenRight(child(a,1),t+1)||
        "subi t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);
    }
  }
  else if (a->kind=="/") {
    c=GenRight(child(a,0),t)||
      GenRight(child(a,1),t+1)||
      "divi t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);
  }
  else if (a->kind=="*") {
    c=GenRight(child(a,0),t)||
      GenRight(child(a,1),t+1)||
      "muli t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);
  }
  else if (a->kind=="<") {
    c=GenRight(child(a,0),t)||
      GenRight(child(a,1),t+1)||
      "lesi t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);
  }
  else if (a->kind==">") {
    c=GenRight(child(a,0),t)||
      GenRight(child(a,1),t+1)||
      "grti t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);
  }
  else if (a->kind=="=") {
    c=GenRight(child(a,0),t)||
      GenRight(child(a,1),t+1)||
      "equi t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);
  }
  else if (a->kind=="and") {
    c=GenRight(child(a,0),t)||
      GenRight(child(a,1),t+1)||
      "land t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);
  }
  else if (a->kind=="or") {
    c=GenRight(child(a,0),t)||
      GenRight(child(a,1),t+1)||
      "loor t"+itostring(t)+" t"+itostring(t+1)+" t"+itostring(t);
  }
  else if (a->kind=="not") {
    c=GenRight(child(a,0),t)||
      "lnot t"+itostring(t)+" t"+itostring(t);
  }
  else if (a->kind=="(") {
    // Per als tipus bàsics apilem primer de tot un paràmetre buit (0)
    // I el desapilem al registre on volem el resultat
    if (isbasickind(symboltable[child(a,0)->text].tp->right->kind)) {
      c=c||"pushparam 0";
      // Cridem a la funció
      c = c||GenCall(a,t);
      // Ara, en cas de ser tipus bàsic, movem el resultat a t0
      c=c||"popparam t"+itostring(t);
    }
  }
  else {
    cout<<"BIG PROBLEM! No case defined for kind "<<a->kind<<endl;
  }
  //cout<<"Ending with node \""<<a->kind<<"\""<<endl;
  return c;
}

// ...to be completed:
codechain CodeGenInstruction(AST *a,string info="")
{
  codechain c;

  if (!a) {
    return c;
  }
  //cout<<"Starting with node \""<<a->kind<<"\""<<endl;
  offsetauxspace=0;
  if (a->kind=="list") {
    for (AST *a1=a->down;a1!=0;a1=a1->right) {
      c=c||CodeGenInstruction(a1,info);
    }
  }
  else if (a->kind=="(") {
    c=GenCall(a,0);
  }
  else if (a->kind==":=") {
    if (isbasickind(child(a,0)->tp->kind)) {
      c=GenLeft(child(a,0),0)||GenRight(child(a,1),1)||"stor t1 t0";
    }
    else if (child(a,1)->ref) {
      c=GenLeft(child(a,0),0)||GenLeft(child(a,1),1)||"copy t1 t0 "+itostring(child(a,1)->tp->size);
    }
    else {
      c=GenLeft(child(a,0),0)||GenRight(child(a,1),1)||"copy t1 t0 "+itostring(child(a,1)->tp->size);
    }
  } 
  else if (a->kind=="while") {
    string numw = itostring(newLabelWhile());
    c="etiq while_"+numw;
    c=c||GenRight(child(a,0),0);   // Calcula el valor de la condicio a t0
    c=c||"fjmp t0 endwhile_"+numw;  // Salta a endwhile si es falsa
    
    c=c||CodeGenInstruction(child(a,1),info);

    c=c||"ujmp while_"+numw;  // Torna al principi per reavaluar la condició i iterar
    c=c||"etiq endwhile_"+numw;
  }
  else if (a->kind=="if") {
    string numi = itostring(newLabelIf());
    bool hihaelse = (child(a,2) != 0);

    c=GenRight(child(a,0),0);   // Calcula el valor de la condicio a t0
    if (not hihaelse)
      c=c||"fjmp t0 endif_"+numi;  // Salta a endif si es falsa
    else
      c=c||"fjmp t0 else_"+numi;  // Salta a else si es falsa
    
    c=c||CodeGenInstruction(child(a,1),info);  // Codi del IF

    if (hihaelse) {
      c=c||"ujmp endif_"+numi;  // Salt al endif, per evitar executar el else
      c=c||"etiq else_"+numi;   // Aqui comença el else
      
      c=c||CodeGenInstruction(child(a,2),info);  // Codi del ELSE
    }

    c=c||"etiq endif_"+numi;
  }

  else if (a->kind=="write" || a->kind=="writeln") {
    if (child(a,0)->kind=="string") {
      c="wris "+child(a,0)->text;
    } 
    else {//Exp
      c=GenRight(child(a,0),0)||"wrii t0";
    }

    if (a->kind=="writeln") {
      c=c||"wrln";
    }
  }
  //cout<<"Ending with node \""<<a->kind<<"\""<<endl;

  return c;
}

void CodeGenSubroutine(AST *a,list<codesubroutine> &l)
{
  codesubroutine cs;

  //cout<<"Starting with node \""<<a->kind<<"\""<<endl;
  string idtable=symboltable.idtable(child(a,0)->text);
  cs.name=idtable+"_"+child(a,0)->text;
  symboltable.push(a->sc);
  symboltable.setidtable(idtable+"_"+child(a,0)->text);

  gencodevariablesandsetsizes(a->sc,cs,a->kind=="function");

  AST * subsub = child(child(a,2),0); // Subrutines a dins de una rutina
  while (subsub != 0) {
    CodeGenSubroutine(subsub,l);  // Generem recursivament el codi de les subrutines
    subsub = subsub->right;
  }

  maxoffsetauxspace=0; newLabelIf(true); newLabelWhile(true);
  cs.c=CodeGenInstruction(child(a,3));  // Generem les instruccions per al codi
  // En el cas de ser una funció cal avaluar l'expressió de return i guardarla a returnvalue
  if (child(a,4) != 0) {
    cs.c=cs.c||
          GenRight(child(a,4),0)||
          "stor t0 returnvalue";
  }
  cs.c=cs.c||"retu";  // Afegim el return!

  //...to be done.

  symboltable.pop();
  l.push_back(cs);
  //cout<<"Ending with node \""<<a->kind<<"\""<<endl;

}

void CodeGen(AST *a,codeglobal &cg)
{
  initnumops();
  securemodeon();
  cg.mainsub.name="program";
  symboltable.push(a->sc);
  symboltable.setidtable("program");
  gencodevariablesandsetsizes(a->sc,cg.mainsub);
  for (AST *a1=child(child(a,1),0);a1!=0;a1=a1->right) {
    CodeGenSubroutine(a1,cg.l);
  }
  maxoffsetauxspace=0; newLabelIf(true); newLabelWhile(true);
  cg.mainsub.c=CodeGenInstruction(child(a,2))||"stop";
  if (maxoffsetauxspace>0) {
    variable_data vd;
    vd.name="aux_space";
    vd.size=maxoffsetauxspace;
    cg.mainsub.localvariables.push_back(vd);
  }
  symboltable.pop();
}

