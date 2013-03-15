#include <list>

#include "attribut.h"
#include "uniqueelement.h"
#include "cdata.h"

using namespace std;

Attribut::Attribut(UniqueElement* element, list<CData*>* datas) : m_element(element), m_datas(datas)
{
}

Attribut::~Attribut()
{
}

void Attribut::setElement(UniqueElement* element)
{
	m_element = element;
}

void Attribut::setData(std::list<CData*>* datas)
{
	m_datas = datas;
}

bool Attribut::addData(CData* datas)
{
	bool isNotNull=false;
	if(m_datas!=null)
	{
		m_datas.push_back(datas);
		isNotNull = true;
	}
	return isNotNull;
}

list<CData*> * Attribut::getData()
{
	return m_datas;
}

UniqueElement * Attribut::getElement()
{
	return m_element;
}