 %{

using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "common.h"


void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);

%}

%union {
	char *s;
	std::list<MotherContent*>* lmc;
	DTDDocument* ddtd;
	Declaration decl;
	MultipleElement mix;
	DTDContent cont;
	Declaration::Card card;
	CData cd;
	list<CData*>* lcd;
   
}

%token ELEMENT ATTLIST SUP OUVREPAR FERMEPAR VIRGULE BARRE FIXED EMPTY ANY PCDATA AST PTINT PLUS CDATA
%token <s> NOM TOKENTYPE DECLARATION VALEUR

%type <lmc> dtd_list_opt
%type <ddtd> document
%type <decl> content
%type <mix> mixed
%type <mix> pipes
%type <card> cardinalite_opt
%type <mix> cp
%type <mix> choices
%type <mix> choice
%type <mix> seq
%type <mix> seqs_opt
%type <cd> attribut
%type <lcd> att_definition_opt
%%

document: dtd_list_opt
{
	$$=new DTDDocument($1);
}
;

dtd_list_opt
: dtd_list_opt ATTLIST NOM att_definition_opt SUP
{
	$$=$1;
	$$->push_back(new DTDAttribute(new UniqueElement($3), $4));
}
| dtd_list_opt ELEMENT NOM content SUP
{
	$$=$1;
	$$->push_back(new Declaration($3, $4));
}
| /* vide */
{
	$$=new std::list<MotherContent*>;
}
;

content
: EMPTY
{
	$$->addElement(new Empty());
}
| ANY
{
	$$->addElement(new Any());
}
| mixed
{
	$$->addMultipleElement($1);
}
| children
{
	$$->addMultipleElement($1);
}
;

mixed
: OUVREPAR PCDATA pipes FERMEPAR AST
{
	$$ = new MultipleElement(true, Declaration::NONE);
	$$->addMultipleElement($3, Declaration::AST);
}
| OUVREPAR PCDATA FERMEPAR AST
{
	$$ = new MultipleElement(true, Declaration::NONE);
	$$->addElement(new DTDPCData(), Declaration::AST);
}
| OUVREPAR PCDATA FERMEPAR
{
	$$ = new MultipleElement(true, Declaration::NONE);
	$$->addElement(new DTDPCData(), Declaration::NONE);
}
;

pipes
: pipes BARRE NOM
{
	$$->addElement(new Element($3), Declaration::NONE);
}
| BARRE NOM
{
	$$ = new MultipleElement(true, Declaration::NONE);
	$$->addElement(new DTDPCData());
	$$->addElement(new Element($2));
}
;

children
: choice cardinalite_opt
{
	$$ = new MultipleElement(true, $2);
	$$->addMultipleElement($1);
}
| seq cardinalite_opt
{
	$$ = new MultipleElement(false, $2);
	$$->addMultipleElement($1);
}
| NOM cardinalite_opt
{
	$$ = new MultipleElement(false, $2);
	$$->addElement($1, $2);
}
;

cardinalite_opt
: PTINT
{
	$$=Declaration::PTINT;
}
| AST
{
	$$=Declaration::AST;
}
| PLUS
{
	$$=Declaration::PLUS;
}
| /*vide*/
{
	$$=Declaration::NONE;
}
;

cp
: NOM cardinalite_opt
{
	$$ = new MultipleElement(true, Declaration::NONE);
	$$->addElement($1, $2);
}
| children
{
	$$=$1;
}
;

choice
: OUVREPAR cp choices FERMEPAR
{
	$$->addMultipleElement($2);
	$$->addMultipleElement($3);
}
;

choices
: choices BARRE cp
{
	$$->addMultipleElement($1);
	$$->addMultipleElement($3);
}
| BARRE cp
{
	$$ = new MultipleElement(true, $2);
}
;

seq
: OUVREPAR cp seqs_opt FERMEPAR
{
	$$ = new MultipleElement(false, Declaration::NONE);
	$$->addMultipleElement($2);
	$$->addMultipleElement($3);
}
;

seqs_opt
: seqs_opt VIRGULE cp
{
	$$->addMultipleElement($1);
	$$->addMultipleElement($3);
}
| /*vide*/
{
	$$ = new MultipleElement(false, Declaration::NONE);
}
;

att_definition_opt
: att_definition_opt attribut
{
	$$->push_back(attribut);
}
| /* vide */
{
	$$=new list<CData*>;
}
;

attribut
: NOM CDATA DECLARATION
{
	$$ = new CData($1);
}
;

%%

int main(int argc, char **argv)
{
  int err;

  yydebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = dtdparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else printf("Parse ended with success\n", err);
  return 0;
}

int dtdwrap(void)
{
  return 1;
}

void dtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}
