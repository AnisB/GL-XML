#include "element.h"

Element::Element(string aType, std::list<Content*> aContent)
{
	//TO_DO
}
Element::Element(string aType)
{
	//TO_DO
}

Element::~Element()
{
	//TO_DO
}
	void setContents(std::list<Content*> * aContent);
	void addContent(Content & aContent);

protected:
	std:string type;
	std::list<Content*> * theContent;

};