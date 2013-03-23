/**
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**/

/**
* @file dtdattribute.cpp
* @author Florent Weillaert
*
* @date 15/03/2013
*
* source file for module DTDAttribute
*
*/

//////////////////////////////////////////////////////////////////////////////
//Includes
//////////////////////////////////////////////////////////////////////////////

#include <list>

#include "dtdattribute.h"
#include "uniqueelement.h"
#include "cdata.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

/**
* Constructor
*/
DTDAttribute::DTDAttribute(UniqueElement* element, list<CData*>* datas) :MotherContent(), mElement(element), m_datas(datas)
{
}

/**
* Destructor.
*/
DTDAttribute::~DTDAttribute()
{
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline setElement
void DTDAttribute::setElement(UniqueElement* element)
{
	mElement = element;
}

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline setData
void DTDAttribute::setData(std::list<CData*>* datas)
{
	m_datas = datas;
}

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline addData
bool DTDAttribute::addData(CData* data)
{
	bool isNotNull=false;
	if(m_datas)
	{
		m_datas->push_back(data);
		isNotNull = true;
	}
	return isNotNull;
}

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline getData
list<CData*> * DTDAttribute::getData()
{
	return m_datas;
}

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline getElement
UniqueElement * DTDAttribute::getElement()
{
	return mElement;
}

void DTDAttribute::printDTD()
{
	std::cout<<"<!ATTLIST "<<mElement->getContent();
	for(std::list<CData*>::iterator it=m_datas->begin();it!=m_datas->end();it++)
	{
		std::cout<<std::endl << "        "<< (*it)->getContent()<<" CDATA #IMPLIED";
	}
	std::cout<<std::endl<<">"<<std::endl;
}



std::string DTDAttribute::getName()
{
	return "A" + mElement->getContent();
}
std::string DTDAttribute::createRegex()
{
	std::string regex = "";
	std::list<CData*>::iterator it = m_datas->begin();
	
	if(it != m_datas->end())
	{
		regex+=(*it)->getContent() + "\"[^\"]*\"";
		it++;
	}
	for( ; it != m_datas->end(); it++ )
	{
		regex+="\\s" + (*it)->getContent() + "\"[^\"]*\"";
	}
	
	mElement->getContent();
	switch(mElement->getCard())
	{
		case Declaration::DTD_AST: regex+="*"; break;
		case Declaration::DTD_PLUS: regex+="+"; break;
		case Declaration::DTD_PTINT: regex+="+"; break;
		default: break;
	}
	
	return regex;
}
//
///////////////////////////////////////////////////////////////////////////////
