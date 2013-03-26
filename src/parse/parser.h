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
* @file Parser
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module Parser.cpp
*
*/

#if defined(Parser_RECURSES)
#error Recursive header files inclusion detected in Parser.h
#else // defined(Parser_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Parser_RECURSES

#if !defined Parser_H
/** Prevents repeated inclusion of headers. */
#define Parser_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <stdio.h>
#include <list>

#include <xml/xmldocument.h>
#include <dtd/dtddocument.h>
//////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////
  // class Parser
  /**
* Description of class Parser <p>
*/


	class Parser
	{
	// ----------------------- Standard services ------------------------------

	public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/

	Parser();
	~Parser();
	// ----------------------- Other services ------------------------------
	static std::pair<std::string*,XMLDocument *> parseXML(std::string fileName);
	static DTDDocument * parseDTD(std::string fileName);
	static void handler(int noSignal);
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