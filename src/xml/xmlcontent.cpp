
/**
 * @file XMLContent.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date 15/03/2013
 *
 * Header file for module XMLContent.cpp
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
 #include <xml/xmlcontent.h>
//////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Constructor
 */
 XMLContent::XMLContent ( )
 {
 }

/**
 * Destructor.
 */
 XMLContent::~XMLContent( )
 {
  //Nothing to do
 }



///////////////////////////////////////////////////////////////////////////////
// Interface - public :

 void XMLContent::printXML()
 {
 	std::cout<<"Error"<<std::endl;
 }

 std::string XMLContent::getType()
 {
 	return "error";
 }

 std::list<XMLContent*> XMLContent::getSonList(std::string name)
 {
 	std::list<XMLContent*> emptyList;
 	return emptyList;
 }

 std::list<XMLContent*> XMLContent::getAllContent(std::string name)
 {
 	std::list<XMLContent*> emptyList;
 	return emptyList;
 }
 std::string XMLContent::getOpen()
 {
 	std::string empty;
 	return empty;
 }
 std::string XMLContent::getClose()
 {
 	std::string empty;
 	return empty;
 }

 std::string XMLContent::toString()
{
	return "";
}


// //
///////////////////////////////////////////////////////////////////////////////
