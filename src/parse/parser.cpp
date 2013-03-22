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
 * file Parser.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * date 
 *
 * Source file for module Parser
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <parse/parser.h>
#include <string>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////
extern FILE * xmlin;
extern FILE * dtdin;
int xmlparse(std::string **, XMLDocument**);
int dtdparse();
///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
Parser::Parser ( )
{
}

/**
 * Destructor.
 */
Parser::~Parser( )
{
  //Nothing to do
}




XMLDocument * Parser::parseXML(std::string fileName)
{
	FILE * file;
	file = fopen(fileName.c_str(), "r");
	if(!file) {
		throw 1;
	}
	std::cout << "Parsing XML file : " << fileName << std::endl;
	std::string * nomdtd;
	XMLDocument* xmlDoc;
	xmlin = file;
	xmlparse(&nomdtd, &xmlDoc);
	fclose(file);
	return xmlDoc;
	

}
//DTDDocument * Parser::parseDTD(std::string fileName)
//{

//} 

///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////