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
 * Impl�mentation du constructeur de DTDDocument
 */
DTDDocument::DTDDocument(std::list<MotherContent*>* listContent) : mContents(listContent)
{
}

/**
 * Impl�mentation du destructeur de DTDDocument
 */
DTDDocument::~DTDDocument( )
{
  //Nothing to do
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
 * Impl�mentation de la m�thode displayAsDTDFormat de DTDDocument
 */
void DTDDocument::displayAsDTDFormat()
{
	for(std::list<MotherContent*>::iterator it=mContents->begin();it!=mContents->end();it++)
	{
		(*it)->printDTD();
	}
}

/**
 * Impl�mentation de la m�thode generateRegex de DTDDocument
 */
std::map<std::string, std::string>*  DTDDocument::generateRegex()
{
	std::map<std::string, std::string> * regexMap = new std::map<std::string, std::string>;
	std::list<MotherContent*>::iterator it;
	// parcours de l'ensemble des définitions du fichier
	for( it = mContents->begin(); it != mContents->end(); it++ )
	{
		std::string name = (*it)->getName();
		std::string regex = (*it)->createRegex();
		(*regexMap)[name] = regex;
		// ajout dans la map de la regex liée au nom du contenu (élément ou attribut)
	}
	return regexMap;
}

// //
///////////////////////////////////////////////////////////////////////////////
