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
#include <errors.h>
#include <signal.h>

//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////
 extern FILE * xmlin;
 extern FILE * dtdin;
 int xmlparse(std::string **, XMLDocument**);
 int dtdparse(DTDDocument**);
 using namespace std;

 struct sigaction new_action, old_action;

///////////////////////////////////////////////////////////////////////////////

 void Parser::handler (int signum)
 {
 	std::cerr<<"Grammar error"<<std::endl;
 	throw GRAMMAR_ERROR;

 }



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


///////////////////////////////////////////////////////////////////////////////
// Interface - public :


 std::pair<std::string*,XMLDocument *> Parser::parseXML(std::string fileName)
 {
 	if (signal(SIGSEGV, Parser::handler) == SIG_ERR)
 		printf("\ncan't catch SIGINT\n");
 	FILE * file;
 	file = fopen(fileName.c_str(), "r");
 	if(!file) {
 		throw FILE_NOT_FOUND;
 	}
 	std::string * nomdtd;
 	XMLDocument* xmlDoc;
 	xmlin = file;
 	try
 	{
 		xmlparse(&nomdtd, &xmlDoc);
 	}
 	catch(int e)
 	{
 		std::cerr<<"Grammar error"<<std::endl;
 	}
 	fclose(file);
 	return make_pair(nomdtd,xmlDoc);
 	

 }
 DTDDocument * Parser::parseDTD(std::string fileName)
 {
 	if (signal(SIGSEGV, Parser::handler) == SIG_ERR)
 		printf("\ncan't catch SIGINT\n");
 	FILE * dtdFile;
 	dtdFile = fopen(fileName.c_str(), "r");
 	if(!dtdFile) {
 		throw FILE_NOT_FOUND;
 	}
 	dtdin = dtdFile;
 	DTDDocument* dtdDoc;
 	try
 	{
 		dtdparse(&dtdDoc);
 	}
 	catch(int e)
 	{
 		std::cerr<<"Grammar error"<<std::endl;
 	}
 	fclose(dtdFile);
 	return dtdDoc;
 } 


///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////