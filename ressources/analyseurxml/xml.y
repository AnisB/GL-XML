%{
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "commun.h"
#include "xml.tab.h"
#include <list>
using namespace std;

// ces trois fonctions devront changer de nom dans le cas où l'otion -p est utilisée
int xmlwrap(void);
void xmlerror(string** nom_dtd, XMLDocument ** doc, char *msg);
int xmllex(void);

%}
%union {
   char * s;
   ElementName * en;
   Misc * msc;
   std::string * stringMachin;
   std::list<Misc*> * lstmsc;
   Declaration * dec;
   Element * elt;
   std::list<Element*> * lelt;
   std::list<XMLContent*> *lcnt;
   XMLContent * cnt;
   std::list<XMLAttribute*> * latt;
   Header * header;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE
%token <s> ENCODING VALEUR COMMENT NOM ENNOM DONNEES
%token <en> OBALISEEN OBALISE OBALISESPECIALE FBALISE FBALISEEN XMLVERSION
%type <s> nom
%type <elt> element
%type <msc> misc 
%type <lstmsc> misc_seq_opt
%type <dec> declaration declarations
%type <latt> attributs_opt
%type <lelt> feuilles_style_opt
%type <lcnt> contenu_opt vide_ou_contenu vide_ou_contenu_en ferme_contenu_et_fin ferme_contenu_et_fin_en
%type <header> header_opt

%parse-param{ string** nom_dtd }
%parse-param { XMLDocument** doc}
%%

document
	: header_opt declarations feuilles_style_opt element misc_seq_opt {*doc= new XMLDocument($1,$2,$3,$4,$5); delete $2;}
 ;

header_opt
	: XMLVERSION attributs_opt SUPSPECIAL {$$ = new Header(); $$->mName = "xml"; $$->mAttList=$2; $$->mExists=true;}
 | /*vide*/ {$$ = new Header(); $$->mName = "xml"; $$->mAttList=new std::list<XMLAttribute*>; $$->mExists=false;}
		 ;
 
nom
 : NOM {$$ = $1;}
 | ENNOM {$$ = $1;}
 ;
 
misc_seq_opt
 : misc_seq_opt misc {$$=$1; $$->push_back($2);}
 | /*vide*/ {$$= new std::list<Misc*>;}
 ;

misc
 : COMMENT {$$= new Misc($1);}
 ;

declarations
  : declaration {$$=$1;}
 | /*vide*/ {$$= new Declaration();$$->mExists=false;}
 ;
 
feuilles_style_opt
 : feuilles_style_opt element {$$=$1; $$->push_back($2);}
 | /*vide*/ {$$= new std::list<Element*>;}
 ;

declaration
  : DOCTYPE NOM NOM VALEUR SUP {$$ = new Declaration(); $$->mName1=$2;$$->mName2=$3;$$->mValue=$4;$$->mExists=true;}
 ;

element
 : OBALISE attributs_opt vide_ou_contenu  {$$ = new Element($1->first,$1->second,$2,$3);}
 | OBALISEEN attributs_opt vide_ou_contenu_en  {$$ = new Element($1->first,$1->second,$2,$3);}
 | OBALISESPECIALE attributs_opt SUPSPECIAL {$$ = new Element($1->first,$1->second,$2,new std::list<XMLContent*>);}
 ;

attributs_opt
 : attributs_opt nom EGAL VALEUR {$$=$1;$$->push_back(new XMLAttribute($2,$4));}
 | /*vide*/ {$$= new std::list<XMLAttribute*>;}
 ;

vide_ou_contenu 
 : SLASH SUP {$$=new std::list<XMLContent*>;}
 | ferme_contenu_et_fin SUP {$$=$1;} 
 ;

vide_ou_contenu_en
 : SLASH SUP {$$=new std::list<XMLContent*>;}
 | ferme_contenu_et_fin_en SUP {$$=$1;} 
 ;

ferme_contenu_et_fin
 : SUP contenu_opt FBALISE {$$=$2;}
 ;

ferme_contenu_et_fin_en
 : SUP contenu_opt FBALISEEN {$$=$2;}
 ;

contenu_opt 
 : contenu_opt DONNEES {$$=$1;$$->push_back(new PCData($2));}
 | contenu_opt misc {$$=$1;$$->push_back($2);}
 | contenu_opt element {$$=$1;$$->push_back($2);}
 | /*vide*/  {$$= new std::list<XMLContent*>;}        
 ;


%%

int main(int argc, char **argv)
{
  int err;
  string *result;
  XMLDocument * dc;
  yydebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne

  err=xmlparse(&result,&dc);
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
  dc->displayAsXMLFormat();
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

