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
* @file PCData
* @author Anis Benyoub
* INSTITUTION INSA Lyon
*
*
* Header file for module PCData.cpp
*
*/

#if defined(PCData_RECURSES)
#error Recursive header files inclusion detected in PCData.h
#else // defined(PCData_RECURSES)
/** Prevents recursive inclusion of headers. */
#define PCData_RECURSES

#if !defined PCData_H
/** Prevents repeated inclusion of headers. */
#define PCData_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions
#include "xmlcontent.h"
#include <list>
#include <iostream>
#include <string>
//////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // class PCData
  /**
   * Description of class 'PCData' <p>
   * 
   * @brief La repr&eacute;sentation d'un champ de texte dans l'xml

   */

   class PCData : public XMLContent
   {
	// ----------------------- Standard services ------------------------------

   public:
	/**
	* Constructor
	* @param aValue la valeur de la chaine de carat&egrave;re 
	*/
	PCData(std::string aValue);


	/**
	* Constructor
	* @param aValue laValeur de la chaine de caract&egrave;re
	*/
	PCData(char * aValue);


	/**
	* Destructor
	* @param aValue laValeur de la chaine de caract&egrave;re
	*/
	virtual ~PCData();


	// ------------------------- Other services ------------------------------
	/**
	* Definition setValue
	* @param aValue nouvelle valeur du pcdata
	*/
	void setValue(std::string value);

	/**
	 * Returns the value stored in the PCDATA
	 * 
	 * @return the value of the PCData
	 */
	 std::string getValue();

	/**
	* Affiche sur la sortie standard le noeud
	*/
	void printXML();

	/**
	* Renvoie sous la chaine
	* @return the value of the PCData
	*/
	std::string toString();

	/**
	 * Renvoie le type (et &eacute;ventuellement l'espace de nom) du contenu
	 * 
	 * @return la chaîne de caract&egrave;re d&eacute;crivant le type
	 */
	 std::string getType();

	/**
	* Renvoie la chaine de caract&egrave;re
	*/
	virtual std::string getOpen();

	/**
	* Renvoie une chaine vide
	*/
	virtual std::string getClose(); 


    //--------------------------- Protected attributes---------------------------
	protected:
		std::string mValue; // La valeur de la chaine

	// 
	///////////////////////////////////////////////////////////////////////////////

	}; // Fin de classe

	#endif
#endif
