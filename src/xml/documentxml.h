#ifndef DOCUMENTaH
#define DOCUMENT_H
#include <iostream>
#include "element.h"
#include "xmlattribute.h"
#include "misc.h"


class DocumentXML {
	Element * mRoot;
	list<Element>* mStyleSheet;
	list<XMLAttribute>* mAttributes;
	Misc * comments;
	std::string mName;
	std::string mName2;
	std::string mValue;	

  public:
	DocumentXML(std::string aname, std::string aname2, std::string avalue);
	~DocumentXML();
  };


#endif