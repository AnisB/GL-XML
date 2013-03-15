#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
using namespace std;

class DocumentXML {
	Element element;
	list<Element>* elements;
	list<Attribut>* attributs;
	Misc misc;
	string name;
	string name2;
	string value;	

  public:
	DocumentXML(string _name, string _name2, string _value);
	~DocumentXML();
  };
#endif