 
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
 * @file Content.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Source file for module declaration
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <map>

#include "declaration.h"
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
Declaration::Declaration (string name, list<DTDContent*> type) : MotherContent(), mName(name),mType(type)
{
}

/**
 * Destructor.
 */
Declaration::~Declaration( )
{
  //Nothing to do
}

void Declaration::printDTD()
{
	cout<<"<!ELEMENT "<<mName<<" ";
	for(list<DTDContent*>::iterator it==mType->begin();it!=mType->end();it++)
	{
		(*it)->printDTD();
	}
	cout<<">"<<endl;
}

void Declaration::addElement()
{
	//a faire
}

std::string Declaration::getName()
{

}

std::string Declaration::createRegex()
{
	
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
