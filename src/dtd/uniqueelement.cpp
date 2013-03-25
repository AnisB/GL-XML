

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
 * Impl�mentation du constructeur de UniqueElement
 */
UniqueElement::UniqueElement (std::string content, Declaration::Card card) : DTDContent(), m_content(content), m_card(card)
{
}

/**
 * Impl�mentation du destructeur de UniqueElement
 */
UniqueElement::~UniqueElement( )
{
  //Nothing to do
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :

/**
 * Impl�mentation de la fonction setContent de UniqueElement
 */
void UniqueElement::setContent(std::string content)
{
	m_content=content;
}

/**
 * Impl�mentation de la fonction getContent de UniqueElement
 */
std::string UniqueElement::getContent()
{
	return m_content;
}

/**
 * Impl�mentation de la fonction getCard de UniqueElement
 */
Declaration::Card UniqueElement::getCard()
{
	return m_card;
}

/**
 * Impl�mentation de la fonction setCard de UniqueElement
 */
void UniqueElement::setCard(Declaration::Card card)
{
	m_card=card;
}

/**
 * Impl�mentation de la fonction printDTD de UniqueElement
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
 * Impl�mentation de la fonction createRegex de UniqueElement
 */
string UniqueElement::createRegex()
{
	// on veut une regex de la forme (contenu\s?)card
	// c'est-à-dire le nom de l'élément suivi d'un espace (sauf si c'est le dernier élément)
	// qui peut se répéter plusieurs fois selon sa cardinalité
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
