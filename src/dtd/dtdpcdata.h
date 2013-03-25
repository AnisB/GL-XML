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
* @file DTDPCData.h
* @author Florent Weillaert
* H4214
*
* @date 15/03/2013
*
* Header file for module DTDPCData.cpp
*
*/

#if defined(DTDPCData_RECURSES)
#error Recursive header files inclusion detected in DTDPCData.h
#else // defined(DTDPCData_RECURSES)
/** Prevents recursive inclusion of headers. */
#define DTDPCData_RECURSES

#if !defined DTDPCData_H
/** Prevents repeated inclusion of headers. */
#define DTDPCData_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <dtd/dtdcontent.h>
/////////////////////////////////////////////////////////////////////////////
// class DTDPCData
class DTDPCData : public DTDContent
{
public:
	/**
	 * Constructeur
	 */
	DTDPCData();
	
	/**
	 * Destructeur
	 */
	virtual ~DTDPCData();

	
	/**
	 * Ecrire sur la sortie standard cet &eacute;l&eacute;ment PCDATA au format DTD
	 */
	void printDTD();

	/**
	 * G&eacute;n&egrave;re une expression r&eacute;guli&egrave;re pour un &eacute;l&eacute;ment PCDATA
	 * @return l'expression r&eacute;guli&egrave;re
	 */
	std::string createRegex();

};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
