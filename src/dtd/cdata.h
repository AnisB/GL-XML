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
* @file cdata.h
* @author Florent Weillaert
* H4214
*
* @date 15/03/2013
*
* Header file for module cdata.cpp
*
*/

#if defined(CData_RECURSES)
#error Recursive header files inclusion detected in cdata.h
#else // defined(CData_RECURSES)
/** Prevents recursive inclusion of headers. */
#define CData_RECURSES

#if !defined CData_H
/** Prevents repeated inclusion of headers. */
#define CData_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// class CData
class CData
{
public:
	/**
	 * Constructeur
	 * @param content le contenu de cette chaine de caractere
	 */
	CData(std::string content);
	
	/**
	 * Destructeur
	 */
	virtual ~CData();
	
	/**
	 * remplacer le contenu du CData
	 * @param content le contenu
	 */
	void setContent(std::string content);

	/**
	 * recuperer le contenu de CData
	 * @return le contenu
	 */
	std::string getContent();

	
protected:
	std::string mContent;
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
