 %{

#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "common.h"
#include "dtd.tab.h"

using namespace std;

void dtderror(DTDDocument** doc, char *msg);
int dtdwrap(void);
int dtdlex(void);

%}

%union {
	char *s;
	std::list<MotherContent*>* lmc;
	DTDDocument* ddtd;
	MultipleElement* mix;
	Declaration::Card card;
	CData* cd;
	std::list<CData*>* lcd;
	DTDContent* dtdc;
   
}

%token ELEMENT ATTLIST SUP OUVREPAR FERMEPAR VIRGULE BARRE FIXED EMPTY ANY PCDATA AST PTINT PLUS CDATA
%token <s> NOM TOKENTYPE DECLARATION VALEUR

%type <lmc> dtd_list_opt
%type <ddtd> document
%type <dtdc> content
%type <mix> children
%type <mix> mixed
%type <mix> pipes
%type <card> cardinalite_opt
%type <dtdc> cp
%type <mix> choices
%type <mix> choice
%type <mix> seq
%type <mix> seqs_opt
%type <cd> attribut
%type <lcd> att_definition_opt

%parse-param { DTDDocument** doc}
%%

document: dtd_list_opt
{
	*doc=new DTDDocument($1);
}
;

dtd_list_opt
: dtd_list_opt ATTLIST NOM att_definition_opt SUP
{
	$$=$1;
	$$->push_back(new DTDAttribute(new UniqueElement($3, Declaration::DTD_NONE), $4));
}
| dtd_list_opt ELEMENT NOM content SUP
{
	$$=$1;
	list<DTDContent*>* l = new list<DTDContent*>;
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
	MultipleElement* me = new MultipleElement(false, Declaration::DTD_NONE);	
	me->addElement(new Empty());
	$$=me;
}
| ANY
{
	MultipleElement* me = new MultipleElement(false, Declaration::DTD_NONE);	
	me->addElement(new Any());
	$$=me;
}
| mixed
{
	$$=$1;
}
| children
{
	$$=$1;
}
;

mixed
: OUVREPAR PCDATA pipes FERMEPAR AST
{
	$$ = new MultipleElement(true, Declaration::DTD_AST);
	$$->addMultipleElement($3);
}
| OUVREPAR PCDATA FERMEPAR AST
{
	$$ = new MultipleElement(true, Declaration::DTD_AST);
	$$->addElement(new DTDPCData());
}
| OUVREPAR PCDATA FERMEPAR
{
	$$ = new MultipleElement(true, Declaration::DTD_NONE);
	$$->addElement(new DTDPCData());
}
;

pipes
: pipes BARRE NOM
{
	$$->addElement(new UniqueElement($3, Declaration::DTD_NONE));
}
| BARRE NOM
{
	$$ = new MultipleElement(true, Declaration::DTD_NONE);
	$$->addElement(new DTDPCData());
	$$->addElement(new UniqueElement($2, Declaration::DTD_NONE));
}
;

children
: choice cardinalite_opt
{
	$$ = $1;
	$$->setCard($2);
}
| seq cardinalite_opt //une sequence n'a pas de cardinalité. Laisser ?
{
	$$ = $1;
	$$->setCard($2);
}
/*| NOM cardinalite_opt
{
	$$ = new MultipleElement(false, $2);
	$$->addElement(new UniqueElement($1,Declaration::DTD_NONE));
}*/
;

cardinalite_opt
: PTINT
{
	$$=Declaration::DTD_PTINT;
}
| AST
{
	$$=Declaration::DTD_AST;
}
| PLUS
{
	$$=Declaration::DTD_PLUS;
}
| /*vide*/
{
	$$=Declaration::DTD_NONE;
}
;

cp
: NOM cardinalite_opt
{
	$$ = new UniqueElement($1, $2);
}
| children
{
	$$=$1;
}
;

choice
: OUVREPAR cp choices FERMEPAR
{
	$$=new MultipleElement(true, Declaration::DTD_NONE);
	$$->addElement($2);
	$$->addMultipleElement($3);
}
;

choices
: choices BARRE cp
{
	$$->addElement($3);
}
| BARRE cp
{
	$$ = new MultipleElement(true, Declaration::DTD_NONE);
	$$->addElement($2);
}
;

seq
: OUVREPAR cp seqs_opt FERMEPAR
{
	//$$ = new MultipleElement(false, Declaration::DTD_NONE);
	$$=$3;
	$$->addElementReverse($2);
	//$$->addMultipleElement($3);
}
;

seqs_opt
: seqs_opt VIRGULE cp
{
	$$=$1;
	//$$->addMultipleElement($1);
	$$->addElement($3);
}
| /*vide*/
{
	$$ = new MultipleElement(false, Declaration::DTD_NONE);
}
;

att_definition_opt
: att_definition_opt attribut
{
	$$->push_back($2);
}
| /* vide */
{
	$$=new std::list<CData*>;
}
;

attribut
: NOM CDATA DECLARATION
{
	$$ = new CData($1);
}
;

%%

int dtdwrap(void)
{
  return 1;
}

void dtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}
