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
* @file Element
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module Element.cpp
*
*/

#if defined(Element_RECURSES)
#error Recursive header files inclusion detected in Element.h
#else // defined(Element_RECURSES)
/** Prevents recursive inclusion of headers. */
#define Element_RECURSES

#if !defined Element_H
/** Prevents repeated inclusion of headers. */
#define Element_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include "xmlcontent.h"
#include <list>
#include <string>
#include "xmlattribute.h"
//////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////
  // class Element
  /**
   * Description of class 'Element' <p>
   * 
   * @brief Structure an XML node

   */

class Element : public XMLContent
{
	// ----------------------- Standard services ------------------------------

public:
	/**
	* Constructor.
	*
	* @param aType1: espace de nom du noeud XML
	* @param aType2: nom du noeud XML
	* @param anAttList: Liste des attributs
	* @param aXMLContent: Liste des sous elements(Noeud, PCDatan Commentaires)
	*/
	Element(std::string aType1, std::string aType2,std::list<XMLAttribute*> * anAttList,std::list<XMLContent*>  * aXMLContent);

	/**
	* Constructor.
	*
	* @param aType1: espace de nom du noeud XML
	* @param aType2: nom du noeud XML
	* @param anAttList: Liste des attributs
	* @param isSpecial: Flag qui dit si c'est un stylesheet
	*/
	Element(std::string aType1, std::string aType2,std::list<XMLAttribute*> * anAttList,bool isSpecial);

	/**
	* Destructor
	*/
	virtual ~Element();

	// ----------------------- Other services ------------------------------
	/**
	* Methode qui affiche sur la sortie standard le noeud et recursivement ses fils
	*/
	void printXML();

	std::string childToString();
	/**
	 * Returns a string containing all the attributes of the element and their content.
	 * The content is writen between quotes and each attribute is separated by a space.
	 * Example : attribute1"hello" attribute2"hi"
	 * 
	 * @return the string
	 */
	std::string attributeToString();
	/**
	 * Returns the type (and eventually the namespace) of the content
	 * 
	 * @return the string describing the type
	 */
	std::string getType();
	virtual std::list<XMLContent*> getSonList(std::string name);
	virtual std::list<XMLContent*> getAllContent(std::string name);
	inline std::list<XMLContent*> * getContent()
	{
		if (mContent==NULL)
		{
			throw NILL_CONTENT;
		}
		return mContent;
	}

	std::string operator[](std::string aname);
	virtual std::string getOpen();
	virtual std::string getClose(); 

public:
	/**
	* Definition de la méthode
	* @param *nom parametre* *description parametre*
	*/

	// ------------------------- Protected Datas ------------------------------
protected:
	std::list<XMLContent*> * mContent;
	std::list<XMLAttribute*> * mAttList;
	bool mIsSpecial;


    //--------------------------- Protected attributes---------------------------

protected:
	std::string mType1;	//namespace
	std::string mType2;	//actual type
};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
