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
* @file Empty
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module Empty.cpp
*
*/

#if defined(Empty_RECURSES)
#error Recursive header files inclusion detected in Empty.h
#else // defined(Empty_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Empty_RECURSES

#if !defined Empty_H
/** Prevents repeated inclusion of headers. */
#define Empty_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include "dtdcontent.h"
#include <iostream>
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// class Empty



class Empty : public DTDContent
{
// ----------------------- Standard services ------------------------------
public:
	Empty();
	virtual ~Empty();
	
	void printDTD();
};
// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
