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
* @file XMLContent
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module XMLContent.cpp
*
*/

#if defined(XMLContent_RECURSES)
#error Recursive header files inclusion detected in XMLContent.h
#else // defined(XMLContent_RECURSES)
/** Prevents recursive inclusion of headers. */
#define XMLContent_RECURSES

#if !defined XMLContent_H
/** Prevents repeated inclusion of headers. */
#define XMLContent_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include <iostream>
#include <list>
//////////////////////////////////////////////////////////////////////////////


  /////////////////////////////////////////////////////////////////////////////
  // class XMLContent
  /**
   * Description of class 'XMLContent' <p>
   * 
   * @brief La repr&eacute;sentation d'un contenu de l'arbre xml

   */

   class XMLContent
   {
	// ----------------------- Standard services ------------------------------

   public:
	/**
	* Constructor.
	*/
	XMLContent();

	/**
 	* Destructor
	*/
 	virtual ~XMLContent();



	// ----------------------- Other services ------------------------------
	/**
	 * Renvoie le type (et &eacute;ventuellement l'espace de nom) du contenu
	 * 
	 * @return la chaîne de caract&egrave;re d&eacute;crivant le type
	*/
	 virtual std::string getType();

	/**
	* Affiche sur la sortie standard le noeud
	*/
	virtual void printXML();


	/**
	* Renvoie sur en strin l'element ("" dans ce cas car classe abstraite)
	* @return la chaine de caract&egrave;re
	*/	
	virtual std::string toString();

	/**
	* Renvoie une liste vide
	* @return empty list
	*/
	virtual std::list<XMLContent*> getSonList(std::string name);

	/**
	* Renvoie une liste vide
	* @return empty list
	*/
	virtual std::list<XMLContent*> getAllContent(std::string name);

	/**
	* Renvoie ""
	* @return ""
	*/
	virtual std::string getOpen();
	/**
	* Renvoie ""
	* @return ""
	*/	
	virtual std::string getClose();

	/**
	* Renvoie NULL
	* @return NULL
	*/
	virtual inline std::list<XMLContent*> * getContent()
	{
		return NULL;
	} 
	/**
	* Surcharge de l'operateur []
	* return ""
	*/

	virtual std::string operator[](std::string aname)
	{
		return "";
	}
	// ------------------------- Protected Datas ------------------------------
protected:

};

// 
///////////////////////////////////////////////////////////////////////////////


#endif
#endif
