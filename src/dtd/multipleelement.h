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

#include "dtdcontent.h"
#include "declaration.h"


/////////////////////////////////////////////////////////////////////////////
// class MultipleElement


class MultipleElement : public DTDContent
{
// ----------------------- Standard services ------------------------------
public:
	/**
	 * Constructeur
	 * @param isChoice cet ensemble d'�l�ment est-il un choix (true) ou une s�quence (false) 
	 * @param card la cardinalit� de cet ensemble d'�l�ments
	 */
	MultipleElement(bool isChoice, Declaration::Card card);
	
	/**
	 * Destructeur
	 */
	virtual ~MultipleElement();
	
	/**
	 * Attribuer une nouvelle cardinalit� &agrave; ce groupe d'�l�ment
	 * @param card la nouvelle cardinalit�
	 */
	void setCard(Declaration::Card card);
	
	/**
	 * R�cup�rer la cardinalit� actuelle de ce groupe d'�l�ment
	 * @return la cardinalit�
	 */	
	Declaration::Card getCard(Declaration::Card card);
	
	/**
	 * ajouter un nouveau contenu &agrave; la fin de ce groupe d'�l�ments
	 * @param content le contenu &agrave; ajouter
	 */
	void addElement(DTDContent* content);
	
	/**
	 * ajouter un nouveau contenu au d�but de ce groupe d'�l�ments
	 * @param content le contenu &agrave; ajouter
	 */
	void addElementReverse(DTDContent* content);
	
	/**
	 * ajouter un par un tous les �l�ments d'un autre MultipleElement dans ce groupe d'�l�ments
	 * @param multipleElement l'ensemble d'�l�ment duquel on veut rajouter les �l�ments
	 */
	void addMultipleElement(MultipleElement* multipleElement);
	
	/**
	 * r�cup�rer les �l�ments contenus dans cet ensemble d'�l�ment
	 * @return la liste de contenu
	 */
	std::list<DTDContent*>* getListContent();
	
	/**
	 * Ecrire sur la sortie standard le groupe d'�l�ment au format DTD
	 */
	void printDTD();
	
	/**
	 * Cr�er une expression r�guli�re correspondant &agrave; ce groupe d'�l�ment
	 * @return l'expression r�guli�re
	 */
	std::string createRegex();

private: 
	bool mIsChoice;
	Declaration::Card mCard;
	std::list<DTDContent*>* mListContent;
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
