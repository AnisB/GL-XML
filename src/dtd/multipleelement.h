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
	 * @param isChoice cet ensemble d'élément est-il un choix (true) ou une séquence (false) 
	 * @param card la cardinalité de cet ensemble d'éléments
	 */
	MultipleElement(bool isChoice, Declaration::Card card);
	
	/**
	 * Destructeur
	 */
	virtual ~MultipleElement();
	
	/**
	 * Attribuer une nouvelle cardinalité &agrave; ce groupe d'élément
	 * @param card la nouvelle cardinalité
	 */
	void setCard(Declaration::Card card);
	
	/**
	 * Récupérer la cardinalité actuelle de ce groupe d'élément
	 * @return la cardinalité
	 */	
	Declaration::Card getCard(Declaration::Card card);
	
	/**
	 * ajouter un nouveau contenu &agrave; la fin de ce groupe d'éléments
	 * @param content le contenu &agrave; ajouter
	 */
	void addElement(DTDContent* content);
	
	/**
	 * ajouter un nouveau contenu au début de ce groupe d'éléments
	 * @param content le contenu &agrave; ajouter
	 */
	void addElementReverse(DTDContent* content);
	
	/**
	 * ajouter un par un tous les éléments d'un autre MultipleElement dans ce groupe d'éléments
	 * @param multipleElement l'ensemble d'élément duquel on veut rajouter les éléments
	 */
	void addMultipleElement(MultipleElement* multipleElement);
	
	/**
	 * récupérer les éléments contenus dans cet ensemble d'élément
	 * @return la liste de contenu
	 */
	std::list<DTDContent*>* getListContent();
	
	/**
	 * Ecrire sur la sortie standard le groupe d'élément au format DTD
	 */
	void printDTD();
	
	/**
	 * Créer une expression régulière correspondant &agrave; ce groupe d'élément
	 * @return l'expression régulière
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
