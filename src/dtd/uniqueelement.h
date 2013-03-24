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
* @file UniqueElement
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module UniqueElement.cpp
*
*/

#if defined(UniqueElement_RECURSES)
#error Recursive header files inclusion detected in UniqueElement.h
#else // defined(UniqueElement_RECURSES)
/** Prevents recursive inclusion of headers. */
#define UniqueElement_RECURSES

#if !defined UniqueElement_H
/** Prevents repeated inclusion of headers. */
#define UniqueElement_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
//////////////////////////////////////////////////////////////////////////////
#include "dtdcontent.h"
#include "declaration.h"
#include <string>
#include <iostream>
/////////////////////////////////////////////////////////////////////////////
// class UniqueElement

class UniqueElement : public DTDContent
{
// ----------------------- Standard services ------------------------------

public:
	UniqueElement(std::string content, Declaration::Card card);
	virtual ~UniqueElement();
	
	/**
	* remplacer le contenu du CData
	* @param content le contenu
	*/
	void setContent(std::string content);

	/**
	* recuperer le contenu de CData
	* @return le contenu
	*/
	std::string getContent();
	
	/**
	* recuperer la cardinalité
	* @return la cardinalité
	*/
	Declaration::Card getCard();
	
	/**
	* remplacer la cardinalité
	* @param card la nouvelle cardinalité
	*/
	void setCard(Declaration::Card card);
	
	/**
	* Ecrire sous forme de DTD
	*/
	void printDTD();
	/**
	 * Genère une expression régulière pour un élément unique
	 * 
	 * @return l'expression régulière
	 */
	std::string createRegex();

	

protected:
	std::string m_content;
	Declaration::Card m_card;

};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
