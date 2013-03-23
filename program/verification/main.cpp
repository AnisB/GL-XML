 
#include <iostream>
#include <stdio.h>
#include <string>
#include <list>

#include <xml/xmldocument.h>
#include <xml/element.h>
#include <xml/xmlcontent.h>

#include <dtd/dtddocument.h>

#include <boost/regex.hpp>

using namespace std;

extern FILE * xmlin;
int xmlparse(string **, XMLDocument**);
extern FILE * dtdin;
int dtdparse(DTDDocument** doc);
bool recursiveCheck(Element * node, map<string,string>*);


int main(int argc, char ** argv)
{
	FILE * file;
	file = fopen(argv[1], "r");
	if(!file) {
		throw 1;
		return -1;
	}
	cout << "Parsing XML file : " << argv[1] << endl;
	string * nomdtd = new string;
	XMLDocument* xmlDoc;
	xmlin = file;
	xmlparse(&nomdtd, &xmlDoc);
	*nomdtd = xmlDoc->getDeclaration()->mValue;
	fclose(file);
	
	Element * node = xmlDoc->getRoot();
	
	
	
	
	cout << "DTD file : " << *nomdtd << endl;
	FILE * dtdFile;
	dtdFile = fopen(nomdtd->data(), "r");
	if(!dtdFile) {
		throw 1;
		return -1;
	}
	cout << "Parsing DTD file : " << *nomdtd << endl;
	dtdin = dtdFile;
	DTDDocument* dtdDoc;
	dtdparse(&dtdDoc);
	fclose(dtdFile);
	
	map<string,string>* regex_map = dtdDoc->generateRegex();
	
	// cout << endl << endl << endl;
	cout<<"Before recursive"<<endl;
	cout<<"Result "<<recursiveCheck(node, regex_map)<<endl;
	
	return 0;
} 


bool recursiveCheck(Element * node, map<string,string>* regex_map)
{
	list<XMLContent*>::iterator it;
	
	string childs = node->childToString();
	string attributes = node->attributeToString();
	string type = node->getType();
	if((*regex_map).find("E"+type)==(*regex_map).end())
	{
		return false;
	}
	boost::regex attributeRegex((*regex_map)["A"+type]);
	boost::regex elementRegex((*regex_map)["E"+type]);
	if( !boost::regex_match(attributes, attributeRegex) )
	{
		// cout << attributes << " and " <<  (*regex_map)["A"+type] << " do not match" << endl;
		return false;
	}
	else
	{
		// cout << attributes << " and " <<  (*regex_map)["A"+type] << " do match" << endl;
	}
	
	if( !boost::regex_match(childs, elementRegex) )
	{
		// cout << childs << " and " <<  (*regex_map)["E"+type] << " do not match" << endl;
		return false;
	}
	else
	{
		// cout << childs << " and " <<  (*regex_map)["E"+type] << " do match" << endl;
	}
	
	for( it = node->getContent()->begin() ; it != node->getContent()->end(); it++)
	{
		if( (*it)->getType().compare("PCDATA") !=  0)
		{
			if( !recursiveCheck((Element*)*it, regex_map) ) return false;
		}
	}
	
	
	return true;
}
