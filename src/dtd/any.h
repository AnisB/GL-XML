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
* @file Any.h
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module Any.cpp
*
*/

#if defined(Any_RECURSES)
#error Recursive header files inclusion detected in Any.h
#else // defined(Any_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Any_RECURSES

#if !defined Any_H
/** Prevents repeated inclusion of headers. */
#define Any_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <dtd/dtdcontent.h>
#include <iostream>
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// class Any

class Any: public DTDContent
{
// ----------------------- Standard services ------------------------------
public:
	/**
	 * Constructeur
	 */
	Any();
	
	/**
	 * Destructeur
	 */
	virtual ~Any();
	
	/**
	 * Ecrire sur la sortie standard cet �l�ment ANY au format DTD
	 */
	void printDTD();

	/**
	 * Gen�re une expression r�guli�re pour un contenu "Any"
	 * @return l'expression r�guli�re
	 */
	std::string createRegex();
};
// 
///////////////////////////////////////////////////////////////////////////////

#endif
#endif
