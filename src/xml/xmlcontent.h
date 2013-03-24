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
* @file XMLContent
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module XMLContent.cpp
*
*/

#if defined(XMLContent_RECURSES)
#error Recursive header files inclusion detected in XMLContent.h
#else // defined(XMLContent_RECURSES)
/** Prevents recursive inclusion of headers. */
#define XMLContent_RECURSES

#if !defined XMLContent_H
/** Prevents repeated inclusion of headers. */
#define XMLContent_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <string>
#include <list>
//////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////
  // class XMLContent
  /**
* Description of class XMLContent <p>
*/


	class XMLContent
	{
	// ----------------------- Standard services ------------------------------

	public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/
	XMLContent();

	/**
 	* Destructor
	*/
	virtual ~XMLContent();

	/**
	 * Returns the type (and eventually the namespace) of the content
	 * 
	 * @return the string describing the type
	 */
	virtual std::string getType();
	virtual void printXML();

	virtual std::list<XMLContent*> getSonList(std::string name);
	virtual std::list<XMLContent*> getAllContent(std::string name);
	virtual std::string getOpen();
	virtual std::string getClose();
	virtual inline std::list<XMLContent*> * getContent()
	{
		return NULL;
	} 

	// ----------------------- Other services ------------------------------

	virtual std::string operator[](std::string aname)
	{
		return "";
	}

	public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/

	// ------------------------- Protected Datas ------------------------------
  protected:

};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
