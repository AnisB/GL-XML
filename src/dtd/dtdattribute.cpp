

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

#include <dtd/dtdattribute.h>
#include <dtd/uniqueelement.h>
#include <dtd/cdata.h>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

/**
 * Impl&eacute;mentation du constructeur de DTDAttribute
 */
DTDAttribute::DTDAttribute(UniqueElement* element, list<CData*>* datas) :MotherContent(), mElement(element), m_datas(datas)
{
	//Nothing to do
}

/**
 * Impl&eacute;mentation du destructeur de DTDAttribute
 */
DTDAttribute::~DTDAttribute()
{
	std::list<CData*>* m_datas;
	for(std::list<CData*>::iterator it=m_datas->begin(); it!=m_datas->end(); it++)
	{
		delete *it;
	}
	m_datas->clear();
	delete m_datas;
	delete mElement;
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :

/**
 * Impl&eacute;mentation de la m&eacute;thode setElement de DTDAttribute
 */
void DTDAttribute::setElement(UniqueElement* element)
{
	mElement = element;
}

/**
 * Impl&eacute;mentation de la m&eacute;thode setData de DTDAttribute
 */
void DTDAttribute::setData(std::list<CData*>* datas)
{
	m_datas = datas;
}

/**
 * Impl&eacute;mentation de la m&eacute;thode addData de DTDAttribute
 */
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

/**
 * Impl&eacute;mentation de la m&eacute;thode getData de DTDAttribute
 */
list<CData*> * DTDAttribute::getData()
{
	return m_datas;
}

/**
 * Impl&eacute;mentation de la m&eacute;thode getElement de DTDAttribute
 */
UniqueElement * DTDAttribute::getElement()
{
	return mElement;
}

/**
 * Impl&eacute;mentation de la m&eacute;thode printDTD de DTDAttribute
 */
void DTDAttribute::printDTD()
{
	std::cout<<"<!ATTLIST "<<mElement->getContent();
	for(std::list<CData*>::iterator it=m_datas->begin();it!=m_datas->end();it++)
	{
		std::cout<<std::endl << "        "<< (*it)->getContent()<<" CDATA #IMPLIED";
	}
	std::cout<<std::endl<<">"<<std::endl;
}

/**
 * Impl&eacute;mentation de la m&eacute;thode getName de DTDAttribute
 */
std::string DTDAttribute::getName()
{
	return "A" + mElement->getContent();
}

/**
 * Impl&eacute;mentation de la m&eacute;thode createRegex de DTDAttribute
 */
std::string DTDAttribute::createRegex()
{
	std::string regex = "";
	std::list<CData*>::iterator it = m_datas->begin();
	
	if(it != m_datas->end())
	{
		// tous les attributs sont #IMPLIED : la regex est de la forme (...)?
		// on cherche une chaîne de caractère de la forme <attribut"valeur">
		// la regex est donc de la forme (attribut"[^"])?, <valeur> pouvant prendre n'importe quel
		// type de caractère hormis "
		regex+='(' + (*it)->getContent() + "\"[^\"]*\"" + ")?";
		it++;
	}
	for( ; it != m_datas->end(); it++ )
	{
		// on rajoute un espace facultatif (on n'est pas garanti d'avoir un attribut avant
		// car ils sont facultatifs) avant chacune des attributs
		regex+= "(\\s?"+ (*it)->getContent() + "\"[^\"]*\"" + ")?";
	}
	
	return regex;
}

//
///////////////////////////////////////////////////////////////////////////////
