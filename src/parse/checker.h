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
* @file Checker
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module Checker.cpp
*
*/

#if defined(Checker_RECURSES)
#error Recursive header files inclusion detected in Checker.h
#else // defined(Checker_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Checker_RECURSES

#if !defined Checker_H
/** Prevents repeated inclusion of headers. */
#define Checker_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <stdio.h>
#include <map>

#include <dtd/dtddocument.h>
#include <xml/xmldocument.h>

//////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////
  // class Checker
  /**
* Description of class Checker <p>
*/


class Checker
{
	// ----------------------- Standard services ------------------------------

public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/

	Checker();
	~Checker();
	// ----------------------- Other services ------------------------------
	static bool check(XMLDocument * xml, DTDDocument * dtd);
	static bool recursiveCheck(Element * node, std::map<std::string,std::string>* regex_map);
	static bool checkXsl(XMLDocument * xml, DTDDocument * dtd);
	static bool recursiveCheckXsl(Element * node, std::map<std::string,std::string>* regex_map);

public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/

	// ------------------------- Protected Datas ------------------------------
protected:

    //--------------------------- Protected attributes---------------------------

protected:
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif