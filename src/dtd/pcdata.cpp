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

/**
* @file pcdata.cpp
* @author Florent Weillaert
*
* @date 15/03/2013
*
* source file for module PCData
*
*/
 
 
//////////////////////////////////////////////////////////////////////////////
//Includes
//////////////////////////////////////////////////////////////////////////////
 
#include <string>

#include "pcdata.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

/**
* Constructor
*/
PCData::PCData(std::string content) : DTDContent(), m_content(content)
{
}

/**
* Destructor.
*/
PCData::~PCData()
{
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline setContent
void PCData::setContent(string content)
{
	m_content = content;
}

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline getContent
string PCData::getContent()
{
	return m_content;
}

//
/////////////////////////////////////////////////////////////////////////////// 
