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
 * file Checker.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * date 
 *
 * Source file for module Checker
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <parse/checker.h>
#include <string>
#include <xml/element.h>
#include <xml/xmlcontent.h>


#include <boost/regex.hpp>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////
 extern FILE * xmlin;
 extern FILE * dtdin;
 int xmlparse(std::string **, XMLDocument**);
 int dtdparse();
 using namespace std;

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
 Checker::Checker ( )
 {
 }

/**
 * Destructor.
 */
 Checker::~Checker( )
 {
  //Nothing to do
 }




 bool Checker::check(XMLDocument * xml, DTDDocument * dtd)
 {
 	return recursiveCheck(xml->getRoot(),dtd->generateRegex());
 }

 bool Checker::recursiveCheck(Element * node, std::map<string,string>* regex_map)
 {
 	list<XMLContent*>::iterator it;

 	string childs = node->childToString();
 	string attributes = node->attributeToString();
 	string type = node->getType();
 	boost::regex attributeRegex((*regex_map)["A"+type]);
 	boost::regex elementRegex((*regex_map)["E"+type]);
 	if( !boost::regex_match(attributes, attributeRegex) )
 	{
 		// cout << attributes << " and " <<  (*regex_map)["A"+type] << " do not match" << endl;
 		return false;
 	}
 	else
 	{
 		// cout << attributes << " and " <<  (*regex_map)["A"+type] << " do match" << endl;
 	}

 	if( !boost::regex_match(childs, elementRegex) )
 	{
 		// cout << childs << " and " <<  (*regex_map)["E"+type] << " do not match" << endl;
 		return false;
 	}
 	else
 	{
 		// cout << childs << " and " <<  (*regex_map)["E"+type] << " do match" << endl;
 	}

 	for( it = node->getContent()->begin() ; it != node->getContent()->end(); it++)
 	{
 		if( (*it)->getType().compare("PCDATA") !=  0)
 		{
 			if( !recursiveCheck((Element*)*it, regex_map) )
 			{
 				return false;
 			} 
 		}
 	}


 	return true;
 }
///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////