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
 * file Element.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * date 
 *
 * Source file for module Element
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include "element.h"
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
Element::Element(std::string aType, std::list<XMLContent*> * aXMLContent)
{
	mType=aType;
	mContent=aXMLContent;
}
Element::Element(std::string aType)
{
	mType=aType;
}

/**
 * Destructor.
 */

Element::~Element()
{
	mContent->clear();
	delete mContent;
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
void Element::setContents(std::list<XMLContent*> * aContent)
{
	mContent=aContent;
}

void Element::addContent(XMLContent * aXMLContent)
{
	mContent->push_back(aXMLContent);
}
///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////