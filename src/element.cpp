#include "element.h"


Element::Element(string aType, std::list<Content*> aContent)
{
	mType=aType;
	mContent
}
Element::Element(string aType)
{
	mType=aType;
}

Element::~Element()
{
	mContent->clear();
}

void Element::setContents(std::list<Content*> * aContent)
{
	mContent=aContent;
}

void Element::addContent(Content * aContent);
{
	mContent->push_back(aContent);
}

};