

/**
 * @file Empty.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Source file for module Empty
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
 #include <dtd/empty.h>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------

using namespace std;

/**
 * Impl&eacute;mentation du constructeur de Empty
 */
Empty::Empty ( )
{
}

/**
 * Impl&eacute;mentation du destructeur de Empty
 */
Empty::~Empty( )
{
  //Nothing to do
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
 * Impl&eacute;mentation de la m&eacute;thode printDTD de Empty
 */
void Empty::printDTD()
{
	cout << "EMPTY";
}

/**
 * Implementation de la m&eacute;thode createRegex de Empty
 */
std::string Empty::createRegex()
{
	// on s'assure que la contrainte vide est réalisée en testant la fin de chaîne
    return "$";
}

// //
///////////////////////////////////////////////////////////////////////////////
