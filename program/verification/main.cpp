 
#include <iostream>
#include <stdio.h>
#include <string>
#include <xmldocument>

using namespace std;

extern FILE * xmlin;
int xmlparse(string **);
extern FILE * dtdin;
int dtdparse();

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
