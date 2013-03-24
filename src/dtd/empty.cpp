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
 * @file Empty.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Source file for module Empty
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
 #include "empty.h"
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

using namespace std;

/**
 * Impl�mentation du constructeur de Empty
 */
Empty::Empty ( )
{
}

/**
 * Impl�mentation du destructeur de Empty
 */
Empty::~Empty( )
{
  //Nothing to do
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
 * Impl�mentation de la m�thode printDTD de Empty
 */
void Empty::printDTD()
{
	cout << "EMPTY";
}

/**
 * Implementation de la m�thode createRegex de Empty
 */
std::string Empty::createRegex()
{
	// on s'assure que la contrainte vide est réalisée en testant la fin de chaîne
    return "$";
}

// //
///////////////////////////////////////////////////////////////////////////////
