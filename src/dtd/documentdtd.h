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
* @file documentdtd
* @author Anis Benyoub
* INSTITUTION
*
* @date date
*
* Header file for module documentdtd.cpp
*
*/

#if defined(documentdtd_RECURSES)
#error Recursive header files inclusion detected in documentdtd.h
#else // defined(documentdtd_RECURSES)
/** Prevents recursive inclusion of headers. */
#define documentdtd_RECURSES

#if !defined documentdtd_H
/** Prevents repeated inclusion of headers. */
#define documentdtd_H

//////////////////////////////////////////////////////////////////////////////
// Inclusions

//////////////////////////////////////////////////////////////////////////////

{

  /////////////////////////////////////////////////////////////////////////////
  // class Content
  /**
* Description of class documentdtd <p>
*/


	class DocumentDtd
	{
	// ----------------------- Standard services ------------------------------

	public:

	DocumentDtd(string aName, string aValue);
	~DocumentDtd();

	/**
	* Remplacer la liste de declaration par une nouvelle liste de declarations
	* @param *aDeclarations  nouvelle liste de declarations
	*/
	void setDeclarations(list<Declaration>* aDeclarations);

	/**
	* Remplacer la liste d'attributs par une nouvelle liste d'attributs
	* @param *aAttributes  nouvelle liste d'attributs
	*/
	void setAttributes(list<Attribut>* aAttributes);
	
	// ------------------------- Protected Datas ------------------------------

  protected:
  // ------------------------- Private Datas --------------------------------

  private:

    //--------------------------- Protected attributes---------------------------

  protected:
	list<Declaration>* declarations;
	list<DTDAttribute>* attributes;
	string name;
	string value;	

// 
///////////////////////////////////////////////////////////////////////////////


#endif
