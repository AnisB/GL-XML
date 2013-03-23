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
	MultipleElement(bool isChoice, Declaration::Card card);
	virtual ~MultipleElement();
	void setCard(Declaration::Card card);
	Declaration::Card getCard(Declaration::Card card);
	void addElement(DTDContent* content);
	void addMultipleElement(MultipleElement multipleElement);
	std::list<DTDContent> getListContent();
	
	/**
	* Ecrire sous forme de DTD
	*/
	void printDTD();

private: 
	bool mIsChoice;
	Declaration::Card mCard;
	std::list<DTDContent*>* mListContent;
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
