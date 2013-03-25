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
* @file MultipleElement
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module MultipleElement.cpp
*
*/

#if defined(MultipleElement_RECURSES)
#error Recursive header files inclusion detected in MultipleElement.h
#else // defined(MultipleElement_RECURSES)
/** Prevents recursive inclusion of headers. */
#define MultipleElement_RECURSES

#if !defined MultipleElement_H
/** Prevents repeated inclusion of headers. */
#define MultipleElement_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
//////////////////////////////////////////////////////////////////////////////
#include <list>
#include <iostream>

#include <dtd/dtdcontent.h>
#include <dtd/declaration.h>


/////////////////////////////////////////////////////////////////////////////
// class MultipleElement


class MultipleElement : public DTDContent
{
// ----------------------- Standard services ------------------------------
public:
	/**
	 * Constructeur
	 * @param isChoice cet ensemble d'&eacute;l&eacute;ment est-il un choix (true) ou une s&eacute;quence (false) 
	 * @param card la cardinalit&eacute; de cet ensemble d'&eacute;l&eacute;ments
	 */
	MultipleElement(bool isChoice, Declaration::Card card);
	
	/**
	 * Destructeur
	 */
	virtual ~MultipleElement();
	
	/**
	 * Attribuer une nouvelle cardinalit&eacute; &agrave; ce groupe d'&eacute;l&eacute;ment
	 * @param card la nouvelle cardinalit&eacute;
	 */
	void setCard(Declaration::Card card);
	
	/**
	 * R&eacute;cup&eacute;rer la cardinalit&eacute; actuelle de ce groupe d'&eacute;l&eacute;ment
	 * @return la cardinalit&eacute;
	 */	
	Declaration::Card getCard(Declaration::Card card);
	
	/**
	 * ajouter un nouveau contenu &agrave; la fin de ce groupe d'&eacute;l&eacute;ments
	 * @param content le contenu &agrave; ajouter
	 */
	void addElement(DTDContent* content);
	
	/**
	 * ajouter un nouveau contenu au d&eacute;but de ce groupe d'&eacute;l&eacute;ments
	 * @param content le contenu &agrave; ajouter
	 */
	void addElementReverse(DTDContent* content);
	
	/**
	 * ajouter un par un tous les &eacute;l&eacute;ments d'un autre MultipleElement dans ce groupe d'&eacute;l&eacute;ments
	 * @param multipleElement l'ensemble d'&eacute;l&eacute;ment duquel on veut rajouter les &eacute;l&eacute;ments
	 */
	void addMultipleElement(MultipleElement* multipleElement);
	
	/**
	 * r&eacute;cup&eacute;rer les &eacute;l&eacute;ments contenus dans cet ensemble d'&eacute;l&eacute;ment
	 * @return la liste de contenu
	 */
	std::list<DTDContent*>* getListContent();
	
	/**
	 * Ecrire sur la sortie standard le groupe d'&eacute;l&eacute;ment au format DTD
	 */
	void printDTD();
	
	/**
	 * Cr&eacute;er une expression r&eacute;guli&egrave;re correspondant &agrave; ce groupe d'&eacute;l&eacute;ment
	 * @return l'expression r&eacute;guli&egrave;re
	 */
	std::string createRegex();

	/**
	* Sets the content list to nill
	*/
	void nilListContent();


private: 
	bool mIsChoice;
	Declaration::Card mCard;
	std::list<DTDContent*>* mListContent;
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
