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
 * @file PCData.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Source file for module PCData
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include "pcdata.h"
#include <iostream>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
PCData::PCData(std::string value)
{
	mValue=value;
}

/**
 * Constructor
 */
PCData::PCData(char * value)
{
	mValue= std::string(value);
}

/**
 * Destructor.
 */
PCData::~PCData( )
{
  //Nothing to do
}

void PCData::setValue(std::string value)
{
	mValue=value;
}

std::string PCData::getValue()
{
	return mValue;
}

void PCData::printXML()
{
	std::cout<<mValue;
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //


// //
///////////////////////////////////////////////////////////////////////////////


