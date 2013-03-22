 
#include <iostream>
#include <stdio.h>
#include <string>
#include <list>

#include <xml/xmldocument.h>
#include <xml/element.h>
#include <xml/xmlcontent.h>

using namespace std;

extern FILE * xmlin;
int xmlparse(string **, XMLDocument**);
extern FILE * dtdin;
int dtdparse();
bool recursiveCheck(Element * node);


int main(int argc, char ** argv)
{
	FILE * file;
	file = fopen(argv[1], "r");
	if(!file) {
		return -1;
	}
	cout << "Parsing XML file : " << argv[1] << endl;
	string * nomdtd;
	XMLDocument* xmlDoc;
	xmlin = file;
	xmlparse(&nomdtd, &xmlDoc);
	fclose(file);
	
	Element * node = xmlDoc->getRoot();
	
	recursiveCheck(node);
	
	
	
	/*cout << "DTD file : " << *nomdtd << endl;
	FILE * dtdFile;
	dtdFile = fopen(nomdtd->data(), "r");
	if(!dtdFile) {
		return -1;
	}
	cout << "Parsing DTD file : " << *nomdtd << endl;
	dtdin = dtdFile;
	dtdparse();
	fclose(dtdFile);*/
	
	
	
	return 0;
} 


bool recursiveCheck(Element * node)
{
	list<XMLContent*>::iterator it;
	
	cout << node->childToString() << endl;
	cout << node->attributeToString() << endl;
	
	for( it = node->getContent()->begin() ; it != node->getContent()->end(); it++)
	{
		if( (*it)->getType().compare("PCDATA") !=  0)
			recursiveCheck((Element*)*it);
	}
	
	
	return true;
}
