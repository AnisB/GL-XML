%{

using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "commun.h"
#include "xml.tab.h"
#include <xml/xmldocument.h>
#include "../../src/xml/misc.h"
#include <list>
// ces trois fonctions devront changer de nom dans le cas où l'otion -p est utilisée
int xmlwrap(void);
void xmlerror(string** nom_dtd, XMLDocument ** doc, char *msg);
int xmllex(void);

%}

%union {
   char * s;
   ElementName * en;
   Misc * msc;
   std::list<Misc*> * lstmsc;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE
%token <s> ENCODING VALEUR DONNEES COMMENT NOM ENNOM
%token <en> OBALISEEN OBALISE OBALISESPECIALE FBALISE FBALISEEN
%type <msc> misc 
%type <lstmsc> misc_seq_opt

%parse-param{ string** nom_dtd }
%parse-param { XMLDocument** doc}
%%

document
 : declarations feuilles_style_opt element misc_seq_opt {*doc= new XMLDocument("lol","lol","lol");}
 ;

misc_seq_opt
 : misc_seq_opt misc {$$=$1; $$->push_back($2);}
 | /*vide*/ {$$= new std::list<Misc*>;}
 ;

misc
 : COMMENT {$$= new Misc($1);}
 ;

declarations
  : declaration
 | /*vide*/
 ;
 
feuilles_style_opt
 : feuilles_style_opt element
 | /*vide*/
 ;

declaration
  : DOCTYPE NOM NOM VALEUR SUP {*nom_dtd = new string($4);}
 ;

element
 : ouvre attributs_opt vide_ou_contenu  
 ;

attributs_opt
 : attributs_opt NOM EGAL VALEUR
 | /*vide*/
 ;

ouvre
 : OBALISE
 | OBALISEEN
 ;

vide_ou_contenu
 : SLASH SUP
 | ferme_contenu_et_fin SUP 
 ;

ferme_contenu_et_fin
 : SUP contenu_opt FBALISE
 ;

contenu_opt 
 : contenu_opt DONNEES 
 | contenu_opt misc 
 | contenu_opt element
 | /*vide*/          
 ;

%%

int main(int argc, char **argv)
{
  int err;
  string *result;
  XMLDocument
  yydebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne

  err = xmlparse(&result,&doc);
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
  else  printf("Parse ended with success. DTD : %s\n", result->data());
  return 0;
}
int xmlwrap(void)
{
  return 1;
}

void xmlerror(string** nom, XMLDocument** doc,char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

