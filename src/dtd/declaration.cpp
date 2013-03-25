
/**
 * @file Content.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Source file for module declaration
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <map>

#include <dtd/declaration.h>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

using namespace std;

/**
 * Impl�mentation du constructeur de Declaration
 */
Declaration::Declaration (string name, DTDContent* type) : MotherContent(), mName(name),mType(type)
{
}

/**
 * Impl�mentation du destructeur de Declaration
 */
Declaration::~Declaration( )
{
	delete mType;
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
 * Impl�mentation de la m�thode getName de Declaration
 */
void Declaration::printDTD()
{
	cout<<"<!ELEMENT "<<mName<<" ";
	mType->printDTD();
	cout<<">"<<endl;
}

/**
 * Impl�mentation de la m�thode getName de Declaration
 */
std::string Declaration::getName()
{
	return "E"+mName;
}

/**
 * Impl�mentation de la m�thode getName de Declaration
 */
std::string Declaration::createRegex()
{
	return mType->createRegex();
}

// //
///////////////////////////////////////////////////////////////////////////////
