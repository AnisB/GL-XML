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

#pragma once

/**
* @file attribut.h
* @author Florent Weillaert
* H4214
*
* @date 15/03/2013
*
* Header file for module dtdattribute.cpp
*
*/

#if defined(DTDAttribute_RECURSES)
#error Recursive header files inclusion detected in dtdattribute.h
#else // defined(DGtalNode_RECURSES)
/** Prevents recursive inclusion of headers. */
#define DTDAttribute_RECURSES

#if !defined DTDAttribute_H
/** Prevents repeated inclusion of headers. */
#define DTDAttribute_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
//////////////////////////////////////////////////////////////////////////////

#include <list>

#include "cdata.h"
#include "uniqueelement.h"

/////////////////////////////////////////////////////////////////////////////
// class DTDAttribute
/**
* Cette classe contient les attributs
*/

class DTDAttribute
{
public:
	DTDAttribute(UniqueElement* element, std::list<CData*>* datas);
	virtual ~DTDAttribute();

	/**
	* remplacer l'élément de l'attribut
	* @param element le nouvel élément
	*/
	void setElement(UniqueElement* element);
	/**
	* remplacer la liste de données par une nouvelle liste
	* @param datas les nouvelles données
	*/
	void setData(std::list<CData*>* datas);
	/**
	* ajouter une donnée à la liste de données de l'attribut
	* @param data la donnée à ajouter
	* @return true si la donnée à bien été ajoutée et false sinon
	*/
	bool addData(CData* data);
	
	/**
	* Récupérer les données contenues dans cet attribut
	* @return datas les données de l'attribut
	*/
	std::list<CData*> * getData();
	/**
	* Récupérer l'élément que contient l'attribut considéré
	* @return l'élément de l'attribut
	*/
	UniqueElement * getElement();

protected:
	std::list<CData*>* m_datas;
	UniqueElement* m_element;
};

// 
///////////////////////////////////////////////////////////////////////////////

#endif
#endif
