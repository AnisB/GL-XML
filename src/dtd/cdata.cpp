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
* @file cdata.cpp
* @author Florent Weillaert
*
* @date 15/03/2013
*
* source file for module CData
*
*/
 
 
//////////////////////////////////////////////////////////////////////////////
//Includes
#include <string>

#include "cdata.h"
//////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

/**
 * Impl�mentation du constructeur de CData
 */
CData::CData(std::string content) : m_content(content)
{
}

/**
 * Impl�mentation du destructeur de CData
 */
CData::~CData()
{
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
 * Impl�mentation de la m�thode setContent de CData
 */
void CData::setContent(string content)
{
	m_content = content;
}

/**
 * Impl�mentation de la m�thode getContent de CData
 */
string CData::getContent()
{
	return m_content;
}
//
/////////////////////////////////////////////////////////////////////////////// 
