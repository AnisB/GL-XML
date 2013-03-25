
/**
 * file XMLDocument.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * date 
 *
 * Source file for module XMLDocument
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <xml/xmldocument.h>
 #include <iostream>
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
XMLDocument::XMLDocument( Header * aHead, XmlDeclaration * aDec, std::list<Element*> *stylesheet, Element* root, std::list<Misc*> * alist)
{
	mHeader = aHead;
	mDec = aDec;
	mMiscList = alist;
	mRoot=root;
	mStyleSheet=stylesheet;
}


/**
 * Destructor.
 */
 XMLDocument::~XMLDocument()
 {
 	for(std::list<Element*>::iterator it=mStyleSheet->begin(); it!=mStyleSheet->end();it++)
 	{
 		delete *it;
 	}
 	mStyleSheet->clear();
 	delete mStyleSheet;

 	for(std::list<Misc*>::iterator it=mMiscList->begin(); it!=mMiscList->end();it++)
 	{
 		delete *it;
 	}
 	mMiscList->clear();
 	delete mMiscList;


 	delete mRoot;

 	delete mDec;

 	delete mHeader;

 }


///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
* Displays the node as an xml node
*/
void XMLDocument::displayAsXMLFormat()
{
	mHeader->printXML();
	mDec->printXML();
	for(std::list<Misc*>::iterator it=mMiscList->begin();it!=mMiscList->end();it++)
	{
		(*it)->printXML();
	}

	for(std::list<Element*>::iterator it=mStyleSheet->begin();it!=mStyleSheet->end();it++)
	{
		(*it)->printXML();
	}

	mRoot->printXML();
}


// //
///////////////////////////////////////////////////////////////////////////////
