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
* @file dtddocument
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module dtddocument.cpp
*
*/

#if defined(dtddocument_RECURSES)
#error Recursive header files inclusion detected in dtddocument.h
#else // defined(dtddocument_RECURSES)
/** Prevents recursive inclusion of headers. */
#define dtddocument_RECURSES

#if !defined dtddocument_H
/** Prevents repeated inclusion of headers. */
#define dtddocument_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <list>
#include <string>
#include <map>

#include "declaration.h"
#include "dtdattribute.h"

/////////////////////////////////////////////////////////////////////////////
// class DTDDocument


class DTDDocument
{
// ----------------------- Standard services ------------------------------

public:

	DTDDocument(std::list<MotherContent*>* listContent);
	~DTDDocument();
	void displayAsDTDFormat();
	
	std::map<std::string, std::string> * generateRegex();

protected:

	std::list<MotherContent*>* mContents;	
};
// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
