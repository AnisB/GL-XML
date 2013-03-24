 
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
 * Implémentation du constructeur de Declaration
 */
Declaration::Declaration (string name, DTDContent* type) : MotherContent(), mName(name),mType(type)
{
}

/**
 * Implémentation du destructeur de Declaration
 */
Declaration::~Declaration( )
{
  //Nothing to do
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
 * Implémentation de la méthode getName de Declaration
 */
void Declaration::printDTD()
{
	cout<<"<!ELEMENT "<<mName<<" ";
	mType->printDTD();
	cout<<">"<<endl;
}

/**
 * Implémentation de la méthode getName de Declaration
 */
std::string Declaration::getName()
{
	return "E"+mName;
}

/**
 * Implémentation de la méthode getName de Declaration
 */
std::string Declaration::createRegex()
{
	return mType->createRegex();
}

// //
///////////////////////////////////////////////////////////////////////////////
