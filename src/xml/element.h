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
* INSA Lyon
*
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
#include <errors.h>
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
	* Methode qui affiche sur la sortie standard le noeud et recursivement ses fils sous le format xml
	*/
	void printXML();

	/**
	* Methode qui affiche renvoie sous la forme de chaine de carat&egrave;res  le noeud et recursivement ses fils
	*/
	std::string toString();

	/**
	 * Renvoie une chaîne de caract&egrave;res contenant tous les enfants de l'&eacute;l&eacute;ment et leur contenu.
	 * Le contenu est &eacute;crit entre guillemets et tous les attributs sont s&eacute;par&eacute;s par un espace.
	 * Exemple : door son
	 * 
	 * @return la chaîne de caract&egrave;re
	 */
	std::string childToString();

	/**
	 * Renvoie une chaîne de caract&egrave;res contenant tous les attributs de l'&eacute;l&eacute;ment et leur contenu.
	 * Le contenu est &eacute;crit entre guillemets et tous les attributs sont s&eacute;par&eacute;s par un espace.
	 * Exemple : attribute1"hello" attribute2"hi"
	 * 
	 * @return la chaîne de caract&egrave;re
	 */
	std::string attributeToString();


	/**
	 * Renvoie le type (et &eacute;ventuellement l'espace de nom) du contenu
	 * 
	 * @return la chaîne de caract&egrave;re d&eacute;crivant le type
	 */
	std::string getType();

	/**
	 * Renvoie la liste des contenu child d'un noeud d'un type donn&eacute;
	 * 
	 * @param name: Le Type &agrave; chercher
	 * @return la chaîne de caract&egrave;re d&eacute;crivant le type
	 */	
	virtual std::list<XMLContent*> getSonList(std::string name);

	/**
	 * Renvoie la liste des contenu child d'un noeud d'un type donn&eacute; et ce de mani&egrave;re r&eacute;cursive
	 * 
	 * @param name: Le Type &agrave; chercher
	 * @return la chaîne de caract&egrave;re d&eacute;crivant le type
	 */	
	virtual std::list<XMLContent*> getAllContent(std::string name);


	/**
	 * Renvoie la liste des contenu child d'un noeud 
	 * 
	 * @return la chaîne de caract&egrave;re d&eacute;crivant le type
	 */	
	inline std::list<XMLContent*> * getContent()
	{
		if (mContent==NULL)
		{
			throw NILL_CONTENT;
		}
		return mContent;
	}

	/**
	 * Force a null la valeur des contenus
	 * @return la chaîne de caract&egrave;re d&eacute;crivant le type
	 */	
	inline void setNullContent()
	{
		mContent=NULL;
	}
	/**
	 * Surcharge le l'operateur [] pour acceder &agrave; un attribut
	 * 
	 * @param aname: L'attribut &agrave; chercher
	 * @return "" si l'attribut n'existe pas, ou la valeur de l'attribut
	 */	
	std::string operator[](std::string aname);

	/**
	 * Renvoie en chaine de carat&egrave;re la balise d'ouverture
	 *
	 * @return la balise d'ouverture en string
	 */
	virtual std::string getOpen();

	/**
	 * Renvoie en chaine de carat&egrave;re la balise de fermeture
	 *
	 * @return la balise d'ouverture en string, si c'est xsl:styleshett on renvoie ""
	 */
	virtual std::string getClose(); 

public:

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
