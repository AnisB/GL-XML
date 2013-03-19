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
* @file XMLDocument
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module XMLDocument.cpp
*
*/

#if defined(XMLDocument_RECURSES)
#error Recursive header files inclusion detected in XMLDocument.h
#else // defined(XMLDocument_RECURSES)
/** Prevents recursive inclusion of headers. */
#define XMLDocument_RECURSES

#if !defined XMLDocument_H
/** Prevents repeated inclusion of headers. */
#define XMLDocument_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <iostream>
#include "element.h"
#include "xmlattribute.h"
#include "misc.h"
//////////////////////////////////////////////////////////////////////////////

typedef struct TDeclaration
{
	std::string mName1;
	std::string mName2;
	std::string mValue;
} Declaration;

typedef struct THeader
{
	std::string mName;
	std::list<XMLAttribute*> * mAttList;
} Header;
  /////////////////////////////////////////////////////////////////////////////
  // class XMLDocument
  /**
* Description of class XMLDocument <p>
*/


	class XMLDocument
	{
	// ----------------------- Standard services ------------------------------

	public:
	/**
	* Constructor
	*/
	XMLDocument( Header * aHead, Declaration * aDec, std::list<Element*>  * stylesheet, Element* root, std::list<Misc*> * alist);
	

	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/
	~XMLDocument();
	// ----------------------- Other services ------------------------------

	public:
	/**
	* Displays the node as an xml node
	*/
	void displayAsXMLFormat();

	// ------------------------- Protected Datas ------------------------------
  protected:
  	std::string mName;
	Element * mRoot;
	std::list<Element*>* mStyleSheet;
	std::list<XMLAttribute*>* mAttributes;
	std::list<Misc*> * mMiscList;
	std::string mName1;
	std::string mName2;
	std::string mValue;	

    //--------------------------- Protected attributes---------------------------

  protected:
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif