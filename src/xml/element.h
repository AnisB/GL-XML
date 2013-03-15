
#include "content.h"
#include <list>
class Element : public Content
{
public:
	Element(string aType, std::list<Content*> aContent);
	Element(string aType);
	virtual ~Element();
	void setContents(std::list<Content*> * aContent);
	void addContent(Content & aContent);

protected:
	std::string mType;
	std::list<Content*> * mContent;
};