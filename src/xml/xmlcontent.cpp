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
 * @file XMLContent.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date 15/03/2013
 *
 * Header file for module XMLContent.cpp
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
 #include "xmlcontent.h"
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
 XMLContent::XMLContent ( )
 {
 }

/**
 * Destructor.
 */
 XMLContent::~XMLContent( )
 {
  //Nothing to do
 }


 void XMLContent::printXML()
 {
 	std::cout<<"Error"<<std::endl;
 }

 std::string XMLContent::getType()
 {
 	return "error";
 }

 std::list<XMLContent*> XMLContent::getSonList(std::string name)
 {
 	std::list<XMLContent*> emptyList;
 	return emptyList;
 }

 std::list<XMLContent*> XMLContent::getAllContent(std::string name)
 {
 	std::list<XMLContent*> emptyList;
 	return emptyList;
 }
 std::string XMLContent::getOpen()
 {
 	std::string empty;
 	return empty;
 }
 std::string XMLContent::getClose()
 {
 	std::string empty;
 	return empty;
 }
///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
