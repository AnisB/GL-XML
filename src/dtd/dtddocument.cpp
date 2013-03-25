

/**
 * @file dtddocument.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * @date date
 *
 * Source file for module dtddocument
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <iostream>
#include <list>
#include <dtd/dtddocument.h>
//////////////////////////////////////////////////////////////////////////////

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// IMPLEMENTATION of inline methods.
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ----------------------- Standard services ------------------------------



/**
 * Implémentation du constructeur de DTDDocument
 */
DTDDocument::DTDDocument(std::list<MotherContent*>* listContent) : mContents(listContent)
{
}

/**
 * Implémentation du destructeur de DTDDocument
 */
DTDDocument::~DTDDocument( )
{
	for(std::list<MotherContent*>::iterator it=mContents->begin();it!=mContents->end();	it++)
	{
		std::cout<<"One"<<endl;
		delete *it;
	}
	mContents->clear();
	delete mContents;
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
 * Implémentation de la méthode displayAsDTDFormat de DTDDocument
 */
void DTDDocument::displayAsDTDFormat()
{
	for(std::list<MotherContent*>::iterator it=mContents->begin();it!=mContents->end();it++)
	{
		(*it)->printDTD();
	}
}

/**
 * Implémentation de la méthode generateRegex de DTDDocument
 */
std::map<std::string, std::string>*  DTDDocument::generateRegex()
{
	std::map<std::string, std::string> * regexMap = new std::map<std::string, std::string>;
	std::list<MotherContent*>::iterator it;
	// parcours de l'ensemble des dÃ©finitions du fichier
	for( it = mContents->begin(); it != mContents->end(); it++ )
	{
		std::string name = (*it)->getName();
		std::string regex = (*it)->createRegex();
		(*regexMap)[name] = regex;
		// ajout dans la map de la regex liÃ©e au nom du contenu (Ã©lÃ©ment ou attribut)
	}
	return regexMap;
}

// //
///////////////////////////////////////////////////////////////////////////////
