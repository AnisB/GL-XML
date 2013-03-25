

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
#include <dtd/multipleelement.h>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

 using namespace std;

/**
 * Impl&eacute;mentation du constructeur de MultipleElement
 */
 MultipleElement::MultipleElement(bool isChoice, Declaration::Card card) : DTDContent(), mIsChoice(isChoice), mCard(card)
 {
 	mListContent = new list<DTDContent*>;
 }

/**
 * Impl&eacute;mentation du destructeur de MultipleElement
 */
 MultipleElement::~MultipleElement( )
 {
 	if(mListContent!=NULL)
 	{
 		for(std::list<DTDContent*>::iterator it=mListContent->begin(); it!=mListContent->end();++it)
 		{
 			delete *it;
 		}
 		mListContent->clear();
 		delete mListContent;
 	}
 }

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
 * Impl&eacute;mentation de la m&eacute;thode setCard de MultipleElement
 */
 void MultipleElement::setCard(Declaration::Card card)
 {
 	mCard = card;
 }

/**
 * Impl&eacute;mentation de la m&eacute;thode getCard de MultipleElement
 */
 Declaration::Card MultipleElement::getCard(Declaration::Card card)
 {
 	return mCard;
 }

/**
 * Impl&eacute;mentation de la m&eacute;thode addElement de MultipleElement
 */
 void MultipleElement::addElement(DTDContent* content)
 {
 	mListContent->push_back(content);
 }

/**
 * Impl&eacute;mentation de la m&eacute;thode addElementReverse de MultipleElement
 */
 void MultipleElement::addElementReverse(DTDContent* content)
 {
 	mListContent->push_front(content);
 }

/**
 * Impl&eacute;mentation de la m&eacute;thode addMultipleElement de MultipleElement
 */
 void MultipleElement::addMultipleElement(MultipleElement* multipleElement)
 {
 	list<DTDContent*>* lElems = multipleElement->getListContent();
 	mListContent->insert(mListContent->end(), lElems->begin(), lElems->end());
 	multipleElement->nilListContent();
 }

/**
 * Impl&eacute;mentation de la m&eacute;thode getListContent de MultipleElement
 */
 list<DTDContent*>* MultipleElement::getListContent()
 {
 	return mListContent;
 }

/**
 * Impl&eacute;mentation de la m&eacute;thode getListContent de MultipleElement
 */
void MultipleElement::nilListContent()
 {
 	 mListContent=NULL;
 }

/**
 * Impl&eacute;mentation de la m&eacute;thode printDTD de MultipleElement
 */
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

/**
 * Impl&eacute;mentation de la m&eacute;thode createRegex de MultipleElement
 */
 std::string MultipleElement::createRegex()
 {
 	std::string regex = "";
 	std::list<DTDContent*>::iterator it = mListContent->begin();
	// parcours de l'ensemble des contenus
 	if( it != mListContent->end() )
 	{
 		regex+="(";
 			for( ; it != mListContent->end(); it++ )
 			{
			// concaténation des regex des contenus de l'élément
 				regex+=(*it)->createRegex();
			// dans le cas d'un choix, et non d'une séquence, on précise que le contenu est facultatif
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

// //
///////////////////////////////////////////////////////////////////////////////
