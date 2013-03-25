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

#pragma once

/**
* @file XMLDocument
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module XMLDocument.cpp
*
*/

#if defined(XMLDocument_RECURSES)
#error Recursive header files inclusion detected in XMLDocument.h
#else // defined(XMLDocument_RECURSES)
/** Prevents recursive inclusion of headers. */
#define XMLDocument_RECURSES

#if !defined XMLDocument_H
/** Prevents repeated inclusion of headers. */
#define XMLDocument_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <xml/element.h>
#include <xml/xmlattribute.h>
#include <xml/misc.h>
//////////////////////////////////////////////////////////////////////////////

typedef struct TDeclaration
{
	std::string mName1;
	std::string mName2;
	std::string mValue;
	bool mExists;

	void printXML()
	{
		if (mExists)
		{
			std::cout<<"<!DOCTYPE "<<mName1<<" "<<mName2<<" \""<<mValue<<"\" >";

		}
	}

	std::string toString()
	{
		std::string toReturn;
		if (mExists)
		{
			toReturn="<!DOCTYPE "+mName1+" "+mName2+" \""+mValue+"\" >";

		}
		return toReturn;
	}
	void copy(struct TDeclaration * aDec)
	{
		this->mName1 = aDec->mName1;
		this->mName2 =aDec->mName2;
		this->mValue =aDec->mValue;
		this->mExists=aDec->mExists;
	}	
} XmlDeclaration;

typedef struct THeader
{
	std::string mName;
	std::list<XMLAttribute*> * mAttList;
	bool mExists;

	void printXML()
	{
		if (mExists)
		{
			std::cout<<"<?xml"; 
			for(std::list<XMLAttribute*>::iterator it= mAttList->begin();it!= mAttList->end();it++)
			{
				(*it)->printXML();
			}
			std::cout<<">"<<std::endl;
		}
	}

	std::string toString()
	{
		if (mExists)
		{
			std::string toReturn="<?xml"; 
			for(std::list<XMLAttribute*>::iterator it= mAttList->begin();it!= mAttList->end();it++)
			{
				toReturn+=(*it)->toString();
			}
			toReturn+=">";
			return toReturn;
		}
		return "";
	}
	void copy(struct THeader * aHeader)
	{
		this->mName = aHeader->mName;
		this->mExists=aHeader->mExists;
		this->mAttList =aHeader->mAttList;
		
	}
	~THeader()
	{

		for(std::list<XMLAttribute*>::iterator it= mAttList->begin();it!= mAttList->end();it++)
		{
			delete (*it);
		}
		mAttList->clear();
		delete mAttList;
	}
} Header;

  /////////////////////////////////////////////////////////////////////////////
  // class XMLDocument
  /**
   * Description of class 'XMLDocument' <p>
   * 
   * @brief L'objet qui repr&eacute;sente un document xml
   */



   class XMLDocument
   {
	// ----------------------- Standard services ------------------------------

   public:
	/**
	* Constructor
	* @param aHead pointeur sur le Header
	* @param aDec pointeur sur la d&eacute;claration
	* @param styleshett liste de stylesheets
	* @param root l'element root
	* @param alist liste des commentaires
	*/
	XMLDocument( Header * aHead, XmlDeclaration * aDec, std::list<Element*>  * stylesheet, Element* root, std::list<Misc*> * alist);
	

	/**
	* Destructor.
	*/
	~XMLDocument();
	// ----------------------- Other services ------------------------------

public:
	/**
	* Displays the node as an xml node
	*/
	void displayAsXMLFormat();

	/**
	 * Renvoie un pointeur sur l'&eacute;l&eacute;ment racine du document XML
	 * 
	 * @return une pointeur sur l'&eacute;l&eacute;ment racine
	 */
	 Element * getRoot()
	 {
	 	return mRoot;
	 }


	/**
	 * Renvoie un pointeur sur la d&eacute;claration du document XML
	 * 
	 * @return un pointeur sur la d&eacute;claration
	 */
	 XmlDeclaration * getDeclaration()
	 {
	 	return mDec;
	 }

	// ------------------------- Protected attributes ------------------------------
	protected:
		std::string mName;
		Element * mRoot;
		std::list<Element*>* mStyleSheet;
		std::list<Misc*> * mMiscList;
		XmlDeclaration * mDec;
		Header * mHeader;
	};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
