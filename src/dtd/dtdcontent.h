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
* @file dtdcontent.h
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module DTDContent.cpp
*
*/

#if defined(DTDContent_RECURSES)
#error Recursive header files inclusion detected in dtdcontent.h
#else // defined(DTDContent_RECURSES)
/** Prevents recursive inclusion of headers. */
#define DTDContentent_RECURSES

#if !defined DTDContent_H
/** Prevents repeated inclusion of headers. */
#define DTDContent_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
//////////////////////////////////////////////////////////////////////////////
#include <string>
/////////////////////////////////////////////////////////////////////////////
// class DTDContent
/**
* Description of class DTDContent
*/


class DTDContent
{
public:
// ----------------------- Standard services ------------------------------
	DTDContent();
	virtual ~DTDContent();
	virtual void printDTD();
    virtual std::string createRegex();
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
