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
* @file Element
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module Element.cpp
*
*/

#if defined(Element_RECURSES)
#error Recursive header files inclusion detected in Element.h
#else // defined(Element_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Element_RECURSES

#if !defined Element_H
/** Prevents repeated inclusion of headers. */
#define Element_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include "xmlcontent.h"
#include <list>
#include <string>
#include "xmlattribute.h"
//////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////
  // class Element
  /**
* Description of class Element <p>
*/


class Element : public XMLContent
{
	// ----------------------- Standard services ------------------------------

public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/
	Element(std::string aType1, std::string aType2,std::list<XMLAttribute*> * anAttList,std::list<XMLContent*>  * aXMLContent);

	/**
	* Destructor
	*/
	virtual ~Element();

	// ----------------------- Other services ------------------------------
	void setContents(std::list<XMLContent*> * aXMLContent);
	void addContent(XMLContent * aXMLContent);
	void printXML();
	std::string childToString();
	std::string attributeToString();
	std::string getType();
<<<<<<< HEAD
	virtual std::list<Content*> getSonList(std::string name);

=======
	inline std::list<XMLContent*> * getContent()
	{
		return mContent;
	}
>>>>>>> fc911283731bfb65b40d55867201f15cfc1c8ae4
	
public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/

	// ------------------------- Protected Datas ------------------------------
protected:
	std::list<XMLContent*> * mContent;
	std::list<XMLAttribute*> * mAttList;


    //--------------------------- Protected attributes---------------------------

protected:
	std::string mType1;	//namespace
	std::string mType2;	//actual type
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
