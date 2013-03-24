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
 * @file UniqueElement.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Header file for module UniqueElement.cpp
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
 #include "uniqueelement.h"
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

using namespace std;

/**
 * Implémentation du constructeur de UniqueElement
 */
UniqueElement::UniqueElement (std::string content, Declaration::Card card) : DTDContent(), m_content(content), m_card(card)
{
}

/**
 * Implémentation du destructeur de UniqueElement
 */
UniqueElement::~UniqueElement( )
{
  //Nothing to do
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :

/**
 * Implémentation de la fonction setContent de UniqueElement
 */
void UniqueElement::setContent(std::string content)
{
	m_content=content;
}

/**
 * Implémentation de la fonction getContent de UniqueElement
 */
std::string UniqueElement::getContent()
{
	return m_content;
}

/**
 * Implémentation de la fonction getCard de UniqueElement
 */
Declaration::Card UniqueElement::getCard()
{
	return m_card;
}

/**
 * Implémentation de la fonction setCard de UniqueElement
 */
void UniqueElement::setCard(Declaration::Card card)
{
	m_card=card;
}

/**
 * Implémentation de la fonction printDTD de UniqueElement
 */
void UniqueElement::printDTD()
{
	cout << m_content;
	if(m_card==Declaration::DTD_AST)
	{
		cout << "*";
	}
	else if(m_card==Declaration::DTD_PTINT)
	{
		cout << "?";
	}
	else if(m_card==Declaration::DTD_PLUS)
	{
		cout << "+";
	}
}

/**
 * Implémentation de la fonction createRegex de UniqueElement
 */
string UniqueElement::createRegex()
{
    std::string regex = "(" + m_content;
	regex+="\\s?)";
	switch(m_card)
	{
		case Declaration::DTD_PTINT: regex+="?"; break;
		case Declaration::DTD_AST: regex+="*"; break;
		case Declaration::DTD_PLUS: regex+="+"; break;
		default: break;
	}
	return regex;
}

// //
///////////////////////////////////////////////////////////////////////////////
