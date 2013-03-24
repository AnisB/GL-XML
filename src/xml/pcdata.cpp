
/**
 * @file PCData.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 *
 * Source file for module PCData
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <xml/pcdata.h>
#include <iostream>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
PCData::PCData(std::string value)
{
	mValue=value;
}

/**
 * Constructor
 */
PCData::PCData(char * value)
{
	mValue= std::string(value);
}

/**
 * Destructor.
 */
PCData::~PCData( )
{
  //Nothing to do
}

void PCData::setValue(std::string value)
{
	mValue=value;
}

std::string PCData::getValue()
{
	return mValue;
}

void PCData::printXML()
{
	std::cout<<mValue;
}
std::string PCData::toString()
{
	return mValue;
}

std::string PCData::getType()
{
	return "PCDATA";
}

 std::string PCData::getOpen()
 {
 	return mValue;
 }
 std::string PCData::getClose()
 {
 	std::string empty;
 	return empty;
 }
///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //


// //
///////////////////////////////////////////////////////////////////////////////


