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
#include <xml/element.h>

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
 		std::cout<<"?>";
 	}
 	else
 	{
 		std::cout<<">";

 		
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
 	if( mType1=="")
 	{
 		return (mType2);
 	}
 	return (mType1 + ":" + mType2);
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
		result += '"' + (*it)->getValue() + '"';
 		it++;
 		
 		for( ; it != mAttList->end(); it++ )
 		{
 			result += " " + (*it)->getType();
			result += '"' + (*it)->getValue() + '"';
 		}
 	}
 	return result;
 }
 
 std::list<XMLContent*> Element::getSonList(std::string name)
 {
 	std::list<XMLContent*> toReturn;
 	for(std::list<XMLContent*>::iterator it=mContent->begin() ; it != mContent->end(); it++ )
 	{
 		if(((*it)->getType()==name))
 		{
 			toReturn.push_back(*it);
 		}
 	}
 	return toReturn;
 }


 std::list<XMLContent*> Element::getAllContent(std::string name)
 {
 	std::list<XMLContent*> toReturn;
 	if (getType()==name)
 	{
 		toReturn.push_back(this);
 	}

 	for(std::list<XMLContent*>::iterator it=mContent->begin() ; it != mContent->end(); it++ )
 	{ 		
 		std::list<XMLContent*> result= (*it)->getAllContent(name);
 		for(std::list<XMLContent*>::iterator it=result.begin();it!=result.end();it++)
 		{
 			toReturn.push_back(*it);
 		}
 	}
 	return toReturn;
 }


 std::string Element::operator[](std::string attname)
 {
 	for(std::list<XMLAttribute*>::iterator it=mAttList->begin();it!=mAttList->end();it++)
 	{
 		if ((*it)->getType()==attname)
 		{
 			return(*it)->getValue();
 		}
 	}
 	return "";
 }
 std::string Element::getOpen()
 {
 	std::string toReturn;
 	if (mType1!="")
 	{
 		if (!mIsSpecial)
 		{
 			toReturn+=("<"+mType1+":"+mType2);
 		}
 		else
 		{
 			toReturn+=("<?"+mType1+":"+mType2);
 		}
 	}
 	else
 	{
 		if (mIsSpecial)
 		{
 			toReturn+=("<?"+mType2);
 		}
 		else
 		{
 			toReturn+=("<"+mType2);
 		}

 	}
 	for(std::list<XMLAttribute*>::iterator it= mAttList->begin();it!= mAttList->end();it++)
 	{
 		toReturn += (*it)->toString();
 	}

 	if (mIsSpecial)
 	{
 		toReturn+=("?>");
 	}
 	else
 	{
 		toReturn+=(">");
 	}
 	return toReturn;

 }
 std::string Element::getClose()
 {
 	std::string toReturn;
 	if (mType1!="")
 	{
 		toReturn+="</"+mType1+":"+mType2+">";
 	}
 	else
 	{
 		toReturn+="</"+mType2+">";

 	}
 	return toReturn;
 
}

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
