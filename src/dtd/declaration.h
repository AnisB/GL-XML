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
* @file declaration
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module documentdtd.cpp
*
*/

#if defined(declaration_RECURSES)
#error Recursive header files inclusion detected in declaration.h
#else // defined(declaration_RECURSES)
/** Prevents recursive inclusion of headers. */
#define declaration_RECURSES

#if !defined declaration_H
/** Prevents repeated inclusion of headers. */
#define declaration_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
//////////////////////////////////////////////////////////////////////////////
#include <map>

#include "dtdcontent.h"
#include "mothercontent.h"

/////////////////////////////////////////////////////////////////////////////
// class Declaration
class Declaration : public MotherContent
{
// ----------------------- Standard services ------------------------------

public:
	/**
	* Definition de la classe
	* @param *nom parametre* *description parametre*
	*/
	enum Card{PTINT, AST, PLUS, NONE};
	
	Declaration(std::string name, std::list<std::pair<int, DTDContent> > type);
	~Declaration();
	void printDTD();

  protected:
	std::list<std::pair<int, DTDContent> > mType;
	std::string mName;
};
// 
///////////////////////////////////////////////////////////////////////////////

#endif
#endif
