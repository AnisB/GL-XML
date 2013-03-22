
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
 * file XSLDocument.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * date 
 *
 * Source file for module XSLDocument
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include "xslocument.h"
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------


using namespace std;
/**
* Constructor
*/
XSLDocument( XMLDocument * xsl, XMLDocument *xml);
{
	mXml=xml;
	mXsl=xsl;
}

	
/**
 * Destructor.
 */
XSLDocument::~XSLDocument()
{
}

/**
* Processes the xml file
*/
std::string XSLDocument::process()
{
	std::string htmlFile="<!DOCTYPE html>";
	Element * root= mXml->getRoot();
	
	return "";
}


/**
* Returns the HTML file
*/
std::string XSLDocument::getHTML()
{
	return "";
}


///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
