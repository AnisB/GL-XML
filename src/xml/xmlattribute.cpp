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
 * @file XMLAttribute.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Source file for module XMLAttribute.
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include "xmlattribute.h"
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
XMLAttribute::XMLAttribute(std::string aname, std::string avalue)
{
	mName = aname;
	mValue = avalue;
}

/**
 * Destructor.
 */
XMLAttribute::~XMLAttribute( )
{
  //Nothing to do
}


void XMLAttribute::printXML()
{
	std::cout<<" "<<mName<<"=\""<<mValue<<"\"";
}

std::string XMLAttribute::getType()
{
	return mName;
}
///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
