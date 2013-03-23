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
 * @file MultipleElement.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Header file for module MultipleElement
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include "multipleelement.h"
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

using namespace std;

/**
 * Constructor
 */
MultipleElement::MultipleElement(bool isChoice, Declaration::Card card) : DTDContent(), mIsChoice(isChoice), mCard(card)
{
	mListContent = new list<DTDContent*>;
}

/**
 * Destructor.
 */
MultipleElement::~MultipleElement( )
{
}

void MultipleElement::setCard(Declaration::Card card)
{
	mCard = card;
}

Declaration::Card MultipleElement::getCard(Declaration::Card card)
{
	return mCard;
}

void MultipleElement::addElement(DTDContent* content)
{
	mListContent->push_back(content);
}

void MultipleElement::addElementReverse(DTDContent* content)
{
	mListContent->push_front(content);
}

void MultipleElement::addMultipleElement(MultipleElement* multipleElement)
{
	list<DTDContent*>* lElems = multipleElement->getListContent();
	mListContent->insert(mListContent->end(), lElems->begin(), lElems->end());
}

list<DTDContent*>* MultipleElement::getListContent()
{
	return mListContent;
}

void MultipleElement::printDTD()
{
	cout << "(";
	std::list<DTDContent*>::iterator ite=mListContent->begin();
	if( ite != mListContent->end() )
	{
		(*ite)->printDTD();
		ite++;
	
		for(std::list<DTDContent*>::iterator it=ite;it!=mListContent->end();it++)
		{
			if(mIsChoice)
			{
				cout << " | ";
			}
			else
			{
				cout << ", ";
			}
			(*it)->printDTD();
		}
	}
	cout << ")";
	if(mCard==Declaration::DTD_AST)
	{
		cout << "*";
	}
	else if(mCard==Declaration::DTD_PLUS)
	{
		cout << "+";
	}
	else if(mCard==Declaration::DTD_PTINT)
	{
		cout << "?";
	}
}

std::string MultipleElement::createRegex()
{
	std::string regex = "";
	std::list<DTDContent*>::iterator it = mListContent->begin();
	if( it != mListContent->end() )
	{
		regex+="(";
		for( ; it != mListContent->end(); it++ )
		{
			regex+=(*it)->createRegex();
			/*regex+="(" + (*it)->createRegex();
			regex+="\\s?";
			regex+=")";*/
			if( mIsChoice )
			{
				regex += "?";
			}
		}
		
		regex+=")";
		
		switch(mCard)
		{
			case Declaration::DTD_PTINT: regex+="?"; break;
			case Declaration::DTD_AST: regex+="*"; break;
			case Declaration::DTD_PLUS: regex+="+"; break;
			default: break;
		}
	}
	
    return regex;
}



///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
