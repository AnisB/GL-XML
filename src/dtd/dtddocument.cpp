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
 * @file dtddocument.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Source file for module dtddocument
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <iostream>
#include <list>

#include "dtddocument.h"
//////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
DTDDocument::DTDDocument(std::list<MotherContent*>* listContent) : mContents(listContent)
{
}

/**
 * Destructor.
 */
DTDDocument::~DTDDocument( )
{
  //Nothing to do
}

void DocumentDTD::displayAsDTDFormat()
{
	for(std::list<MotherContent*>::iterator it=mContents->begin();it!=mContents->end();it++)
	{
		(*it)->printDTD();
	}
}
///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
