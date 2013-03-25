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
#include <list>

#include "cdata.h"
#include "uniqueelement.h"
#include "mothercontent.h"
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// class DTDAttribute
/**
* Cette classe contient les attributs
*/

class DTDAttribute : public MotherContent
{
public:
	/**
	 * Constructeur
	 */
	DTDAttribute(UniqueElement* element, std::list<CData*>* datas);
	
	/**
	 * Destructeur
	 */
	virtual ~DTDAttribute();

	/**
	 * remplacer l'&eacute;l&eacute;ment de l'attribut
	 * @param element le nouvel &eacute;l&eacute;ment
	 */
	void setElement(UniqueElement* element);
	
	/**
	 * remplacer la liste de donn&eacute;es par une nouvelle liste
	 * @param datas les nouvelles donn&eacute;es
	 */
	void setData(std::list<CData*>* datas);
	
	/**
	 * ajouter une donn&eacute;e &agrave; la liste de donn&eacute;es de l'attribut
	 * @param data la donn&eacute;e &agrave; ajouter
 	 * @return true si la donn&eacute;e &agrave; bien &eacute;t&eacute; ajout&eacute;e et false sinon
	 */
	bool addData(CData* data);
	
	/**
	* R&eacute;cup&eacute;rer les donn&eacute;es contenues dans cet attribut
	* @return datas les donn&eacute;es de l'attribut
	*/
	std::list<CData*> * getData();
	/**
	 * R&eacute;cup&eacute;rer l'&eacute;l&eacute;ment que contient l'attribut consid&eacute;r&eacute;
	 * @return l'&eacute;l&eacute;ment de l'attribut
	 */
	UniqueElement * getElement();

	/**
	 * Ecrire la liste d'attributs sur la sortie standard au format DTD
	 */
	void printDTD();

	/**
	 * Renvoie le nom de l'attribut pr&eacute;c&eacute;d&eacute; du pr&eacute;fixe "A"
	 * @return le nom
	 */
	std::string getName();
	
	/**
	 * Gen&egrave;re une expression r&eacute;guli&egrave;re bas&eacute;e sur l'attribut
	 * @return l'expression r&eacute;guli&egrave;re
	 */
	std::string createRegex();

protected:
	std::list<CData*>* m_datas;
	UniqueElement* mElement;
};

// 
///////////////////////////////////////////////////////////////////////////////

#endif
#endif
