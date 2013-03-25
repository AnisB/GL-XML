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
#include <dtd/dtdcontent.h>
#include <dtd/declaration.h>
#include <iostream>
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// class UniqueElement

class UniqueElement : public DTDContent
{
// ----------------------- Standard services ------------------------------

public:
	/**
	 * Constructeur
	 *
	 */
	UniqueElement(std::string content, Declaration::Card card);
	
	/**
	 * Destructeur
	 */
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
	 * recuperer la cardinalit&eacute;
	 * @return la cardinalit&eacute;
	 */
	Declaration::Card getCard();
	
	/**
	 * remplacer la cardinalit&eacute;
	 * @param card la nouvelle cardinalit&eacute;
	 */
	void setCard(Declaration::Card card);
	
	/**
	 * Ecrire sur la sortie standard au format DTD l'&eacute;l&eacute;ment
	 */
	void printDTD();

	/**
	 * Gen&egrave;re une expression r&eacute;guli&egrave;re pour un &eacute;l&eacute;ment unique
	 * @return l'expression r&eacute;guli&egrave;re
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
