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
* @file XSLDocument
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module XSLDocument.cpp
*
*/

#if defined(XSLDocument_RECURSES)
#error Recursive header files inclusion detected in XSLDocument.h
#else // defined(XSLDocument_RECURSES)
/** Prevents recursive inclusion of headers. */
#define XSLDocument_RECURSES

#if !defined XSLDocument_H
/** Prevents repeated inclusion of headers. */
#define XSLDocument_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <iostream>
#include "element.h"
#include "xmlattribute.h"
#include "misc.h"
//////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // class XSLDocument
  /**
* Description of class XSLDocument <p>
*/


	class XSLDocument
	{
	// ----------------------- Standard services ------------------------------

	public:
	/**
	* Constructor
	*/
	XSLDocument( XMLDocument * xsl, XMLDocument *xml);
	

	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/
	~XSLDocument();
	// ----------------------- Other services ------------------------------

	public:
	/**
	* Displays the node as an xml node
	*/
	std::string process();

	/**
	* You should call process before getting the xml (This method avoids reprocessing the file)
	*/
	std:string getHTML();
	// ------------------------- Protected Datas ------------------------------
  protected:
  	XMLDocument * mXsl;
	XMLDocument * mXml;

    //--------------------------- Protected attributes---------------------------

  protected:
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
