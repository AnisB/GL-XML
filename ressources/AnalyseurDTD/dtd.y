%{

using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>


void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);

%}

%union { 
   char *s; 
}

%token ELEMENT ATTLIST SUP OUVREPAR FERMEPAR VIRGULE BARRE FIXED EMPTY ANY PCDATA AST PTINT PLUS CDATA
%token <s> NOM TOKENTYPE DECLARATION VALEUR

%%

document: dtd_list_opt

;

dtd_list_opt
: dtd_list_opt ATTLIST NOM att_definition_opt SUP
| dtd_list_opt ELEMENT NOM content SUP
| /* vide */
;

content
: EMPTY
| ANY
| mixed
| children
;

mixed
: OUVREPAR PCDATA pipes_opt FERMEPAR AST
| OUVREPAR PCDATA FERMEPAR
;

pipes_opt
: pipes_opt BARRE NOM
| /*vide*/
;

children
: choice cardinalite_opt
| seq cardinalite_opt
;

cardinalite_opt
: PTINT
| AST
| PLUS
| /*vide*/
;

cp
: NOM cardinalite_opt
| children
;

choice
: OUVREPAR cp choices FERMEPAR
;

choices
: choices BARRE cp
| BARRE cp
;

seq
: OUVREPAR cp seqs_opt FERMEPAR
;

seqs_opt
: seqs_opt VIRGULE cp
| /*vide*/
;

att_definition_opt
: att_definition_opt attribut
| /* vide */
;

attribut
: NOM att_type defaut_declaration
;

att_type
: CDATA
| TOKENTYPE
| type_enumere
;

type_enumere
: OUVREPAR liste_enum_plus FERMEPAR
;

liste_enum_plus
: liste_enum BARRE NOM
;

liste_enum
: NOM
| liste_enum BARRE NOM
;

defaut_declaration
: DECLARATION
| VALEUR
| FIXED VALEUR
;

%%

int main(int argc, char **argv)
{
  int err;

  yydebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = dtdparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n", err);
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
