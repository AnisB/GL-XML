

/**
 * @file XMLAttribute.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Source file for module XMLAttribute.
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <xml/xmlattribute.h>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
XMLAttribute::XMLAttribute(std::string aname, std::string avalue)
{
	// Copie des attributs
	mName = aname;
	mValue = avalue;
}

/**
 * Destructor.
 */
XMLAttribute::~XMLAttribute( )
{
  //Nothing to do
}




///////////////////////////////////////////////////////////////////////////////
// Interface - public :
void XMLAttribute::printXML()
{
	std::cout<<" "<<mName<<"=\""<<mValue<<"\"";
}


std::string XMLAttribute::getType()
{
	return mName;
}


std::string XMLAttribute::getValue()
{
	return mValue;
}


std::string XMLAttribute::toString()
{
	std::string toReturn =(" "+mName+"=\""+mValue+"\"");
	return toReturn;

}

// //
///////////////////////////////////////////////////////////////////////////////
