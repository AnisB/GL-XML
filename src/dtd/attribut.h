#include <list>

#include "cdata.h"
#include "uniqueelement.h"

class Attribut
{
public:
	Attribut(UniqueElement* element, std::list<CData*>* datas);
	virtual ~Attribut();

	void setElement(UniqueElement* element);
	void setData(std::list<CData*>* datas);
	void addData(CData* datas);
	
	std::list<CData*> * getData();
	UniqueElement * getElement();

protected:
	std::list<CData*>* m_datas;
	UniqueElement* m_element;
};