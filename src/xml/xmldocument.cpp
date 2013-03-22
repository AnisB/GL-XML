
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
 * file XMLDocument.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * date 
 *
 * Source file for module XMLDocument
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include "xmldocument.h"
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
XMLDocument::XMLDocument( Header * aHead, Declaration * aDec, std::list<Element*> *stylesheet, Element* root, std::list<Misc*> * alist)
{
	mHeader = new Header();
	mHeader->copy(aHead);
	mDec = new Declaration();
	mDec->copy(aDec);
	mMiscList = alist;
	mRoot=root;
	mStyleSheet=stylesheet;
}

	
/**
 * Destructor.
 */
XMLDocument::~XMLDocument()
{
}

/**
* Displays the node as an xml node
*/
void XMLDocument::displayAsXMLFormat()
{
	//std::cout<<"<?xml encoding=\"utf-8\" version=\"1.0\">\n";

	mHeader->printXML();
	mDec->printXML();
	for(std::list<Misc*>::iterator it=mMiscList->begin();it!=mMiscList->end();it++)
	{
		(*it)->printXML();
	}

	for(std::list<Element*>::iterator it=mStyleSheet->begin();it!=mStyleSheet->end();it++)
	{
		(*it)->printXML();
	}

	mRoot->printXML();
}


///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
