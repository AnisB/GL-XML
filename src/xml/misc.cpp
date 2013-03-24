
/**
 * file Misc.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * date 
 *
 * Source file for module Misc
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <xml/misc.h>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */

 Misc::Misc(std::string aComment)
 {
 	mValue = aComment;
 }


/**
 * Destructor.
 */
 Misc::~Misc( )
 {
  //Nothing to do
 }

///////////////////////////////////////////////////////////////////////////////
// Interface - public :

 void Misc::printXML()
 {
 	std::cout<< mValue<<std::endl;
 }

 std::string Misc::toString()
 {
 	return mValue;
 } 


 std::string Misc::getOpen()
 {
 	return mValue;
 }

 std::string Misc::getClose()
 {
 	return "";
 }

// //
///////////////////////////////////////////////////////////////////////////////
