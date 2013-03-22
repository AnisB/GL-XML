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
 * file Element.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * date 
 *
 * Source file for module Element
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include "element.h"

//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
 Element::Element(std::string aType1,std::string aType2, std::list<XMLAttribute*> * anAttList,std::list<XMLContent*>* aXMLContent)
 {
 	mType1=aType1;
 	mType2=aType2;
 	mContent=aXMLContent;
 	mAttList=anAttList;
 	mIsSpecial=false;
 }


 Element::Element(std::string aType1,std::string aType2, std::list<XMLAttribute*> * anAttList,bool isSpecial)
 {
 	mType1=aType1;
 	mType2=aType2;
 	mAttList=anAttList;
 	mIsSpecial=true;
 }
/**
 * Destructor.
 */

 Element::~Element()
 {
 	mContent->clear();
 	delete mContent;
 }

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
 void Element::setContents(std::list<XMLContent*> * aContent)
 {
 	mContent=aContent;
 }

 void Element::addContent(XMLContent * aXMLContent)
 {
 	mContent->push_back(aXMLContent);
 }

 void Element::printXML()
 {
 	if (mType1!="")
 	{
 		if (!mIsSpecial)
 		{
 			std::cout<<"<"<<mType1<<":"<<mType2;
 		}
 		else
 		{
 			std::cout<<"<?"<<mType1<<":"<<mType2;
 		}
 	}
 	else
 	{
 		if (mIsSpecial)
 		{
 			std::cout<<"<?"<<mType2;
 		}
 		else
 		{
 			std::cout<<"<"<<mType2;
 		}

 	}
 	for(std::list<XMLAttribute*>::iterator it= mAttList->begin();it!= mAttList->end();it++)
 	{
 		(*it)->printXML();
 	}

 	if (mIsSpecial)
 	{
 		std::cout<<"?>";;
 	}
 	else
 	{
 		std::cout<<">";;

 		
 		for(std::list<XMLContent*>::iterator it= mContent->begin();it!= mContent->end();it++)
 		{
 			(*it)->printXML();
 		}
 		if (mType1!="")
 		{
 			std::cout<<"</"<<mType1<<":"<<mType2<<">"<<std::endl;
 		}
 		else
 		{
 			std::cout<<"</"<<mType2<<">"<<std::endl;

 		}
 	}

 }


 std::string Element::childToString()
 {
 	std::string result = "";
 	std::list<XMLContent*>::iterator it = mContent->begin();
 	if( it == mContent-> end() )
 	{
 		return result;
 	}
 	else
 	{
 		result += (*it)->getType();
 		it++;
 		
 		for( ; it != mContent->end(); it++ )
 		{
 			result += " " + (*it)->getType();
 		}
 	}
 	return result;
 }

 std::string Element::getType()
 {
 	if( mType1.compare("") == 0)
 	{
 		return mType2;
 	}
 	return mType1 + ":" + mType2;
 }


 std::string Element::attributeToString()
 {
 	std::string result = "";
 	std::list<XMLAttribute*>::iterator it = mAttList->begin();
 	if( it == mAttList-> end() )
 	{
 		return result;
 	}
 	else
 	{
 		result += (*it)->getType();
 		it++;
 		
 		for( ; it != mAttList->end(); it++ )
 		{
 			result += " " + (*it)->getType();
 		}
 	}
 	return result;
 }
 
 std::list<XMLContent*> Element::getSonList(std::string name)
 {
 	std::list<XMLContent*> toReturn;
 	for(std::list<XMLContent*>::iterator it=mContent->begin() ; it != mContent->end(); it++ )
 	{
 		if( ((*it)->getType()=="Element") && ((*it)->getType()==name))
 		{
 			toReturn.push_back(*it);
 		}
 	}
 }

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
