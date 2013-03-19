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
* @file mothercontent.h
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module mothercontent.cpp
*
*/

#if defined(MotherContent_RECURSES)
#error Recursive header files inclusion detected in mothercontent.h
#else // defined(MotherContent_RECURSES)
/** Prevents recursive inclusion of headers. */
#define MotherContentent_RECURSES

#if !defined MotherContent_H
/** Prevents repeated inclusion of headers. */
#define MotherContent_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
//////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// class MotherContent
/**
* Description of class MotherContent
*/


class MotherContent
{
public:
// ----------------------- Standard services ------------------------------
	MotherContent();
	virtual ~MotherContent();
	virtual void printDTD();
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
