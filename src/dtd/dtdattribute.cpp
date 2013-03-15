#include <list>

#include "dtdattribute.h"
#include "uniqueelement.h"
#include "cdata.h"

using namespace std;

DTDAttribute::DTDAttribute(UniqueElement* element, list<CData*>* datas) : m_element(element), m_datas(datas)
{
}

DTDAttribute::~DTDAttribute()
{
}

void DTDAttribute::setElement(UniqueElement* element)
{
	m_element = element;
}

void DTDAttribute::setData(std::list<CData*>* datas)
{
	m_datas = datas;
}

bool DTDAttribute::addData(CData* data)
{
	bool isNotNull=false;
	if(m_datas!=null)
	{
		m_datas.push_back(datas);
		isNotNull = true;
	}
	return isNotNull;
}

list<CData*> * DTDAttribute::getData()
{
	return m_datas;
}

UniqueElement * DTDAttribute::getElement()
{
	return m_element;
}