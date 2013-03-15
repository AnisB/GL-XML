#include "element.h"


Element::Element(std::string aType, std::list<XMLContent*> * aXMLContent)
{
	mType=aType;
	mContent=aXMLContent;
}
Element::Element(std::string aType)
{
	mType=aType;
}

Element::~Element()
{
	mContent->clear();
}

void Element::setContents(std::list<XMLContent*> * aContent)
{
	mContent=aContent;
}

void Element::addContent(XMLContent * aXMLContent)
{
	mContent->push_back(aXMLContent);
}
