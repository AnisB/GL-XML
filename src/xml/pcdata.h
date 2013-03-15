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
* @file PCData
* @author Anis Benyoub
* INSTITUTION INSA Lyon
*
* @date date
*
* Header file for module PCData.cpp
*
*/

#if defined(PCData_RECURSES)
#error Recursive header files inclusion detected in PCData.h
#else // defined(PCData_RECURSES)
/** Prevents recursive inclusion of headers. */
#define PCData_RECURSES

#if !defined PCData_H
/** Prevents repeated inclusion of headers. */
#define PCData_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include "xmlcontent.h"
#include <list>
#include <iostream>
//////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // class PCData
  /**
* Description of class PCData <p>
*/


	class PCData : public XMLContent
	{
	// ----------------------- Standard services ------------------------------

	public:
	/**
	* Constructor
	* @param aValue string object 
	*/
	PCData(std::string aValue);


	/**
	* Constructor
	* @param aValue string object 
	*/
	PCData(char * aValue);


	/**
	* Destructor
	* @param *nom parametre* *description parametre*
	*/
	virtual ~PCData();


	// ------------------------- Other services ------------------------------
	/**
	* Definition setValue
	* @param aValue nouvelle valeur du pcdata
	*/
	void setValue(std::string value);

	/**
	* Definition de getVlaue
	*/
	std::string getValue();

	/**
	* Affiche sur la sortie standard le noeud
	*/
	void printAsXml();

    //--------------------------- Protected attributes---------------------------
	protected:
		std::string mValue;

	// 
	///////////////////////////////////////////////////////////////////////////////

	}; // Fin de classe

	#endif
#endif