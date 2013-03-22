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
* @file XMLAttribute
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module XMLAttribute.cpp
*
*/

#if defined(XMLAttribute_RECURSES)
#error Recursive header files inclusion detected in XMLAttribute.h
#else // defined(XMLAttribute_RECURSES)
/** Prevents recursive inclusion of headers. */
#define XMLAttribute_RECURSES

#if !defined XMLAttribute_H
/** Prevents repeated inclusion of headers. */
#define XMLAttribute_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <string>
//////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////
  // class XMLAttribute
  /**
* Description of class XMLAttribute <p>
*/


	class XMLAttribute
	{
	// ----------------------- Standard services ------------------------------

	public:
	/**
	* Definition de la classe
	* @param *nom parametre* *description parametre*
	*/
	XMLAttribute(std::string aname, std::string avalue);
	~XMLAttribute();

	void printXML();
	std::string getType();

  protected:
	// ------------------------- Protected Datas ------------------------------
	std::string mName;
	std::string mValue;	

// 
///////////////////////////////////////////////////////////////////////////////

};
#endif
#endif
