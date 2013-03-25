

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
 #include <dtd/uniqueelement.h>
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
	// on veut une regex de la forme (contenu\s?)card
	// c'est-Ã -dire le nom de l'Ã©lÃ©ment suivi d'un espace (sauf si c'est le dernier Ã©lÃ©ment)
	// qui peut se rÃ©pÃ©ter plusieurs fois selon sa cardinalitÃ©
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
