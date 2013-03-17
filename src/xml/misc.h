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
* @file Misc
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module Misc.cpp
*
*/

#if defined(Misc_RECURSES)
#error Recursive header files inclusion detected in Misc.h
#else // defined(Misc_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Misc_RECURSES

#if !defined Misc_H
/** Prevents repeated inclusion of headers. */
#define Misc_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <list>
#include "xmlcontent.h"
//////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////
  // class Misc
  /**
* Description of class Misc <p>
*/


	class Misc :public  XMLContent
	{
	// ----------------------- Standard services ------------------------------

	public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/
	Misc(std::string acomment);
	
	/**
	* Destructor
	*/
	~Misc();
	// ----------------------- Other services ------------------------------

	void printXML();


	public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/
    //--------------------------- Protected attributes---------------------------
  protected:
	std::string mValue;
	std::list<Misc> *miscs;	
};

// 
///////////////////////////////////////////////////////////////////////////////
#endif
#endif
