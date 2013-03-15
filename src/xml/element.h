
#include "xmlcontent.h"
#include <list>
#include <iostream>
class Element : public XMLContent
{
public:
	Element(std::string aType, std::list<XMLContent*>  * aXMLContent);
	Element(std::string aType);
	virtual ~Element();
	void setContents(std::list<XMLContent*> * aXMLContent);
	void addContent(XMLContent * aXMLContent);
protected:
	std::string mType;
	std::list<XMLContent*> * mContent;
};