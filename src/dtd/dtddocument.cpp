
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
 * Impl&eacute;mentation du constructeur de DTDDocument
 */
DTDDocument::DTDDocument(std::list<MotherContent*>* listContent) : mContents(listContent)
{
}

/**
 * Impl&eacute;mentation du destructeur de DTDDocument
 */
DTDDocument::~DTDDocument( )
{
	for(std::list<MotherContent*>::iterator it=mContents->begin();it!=mContents->end();	it++)
	{
		delete *it;
	}
	mContents->clear();
	delete mContents;
}

///////////////////////////////////////////////////////////////////////////////
// Interface - public :
/**
 * Impl&eacute;mentation de la m&eacute;thode displayAsDTDFormat de DTDDocument
 */
void DTDDocument::displayAsDTDFormat()
{
	for(std::list<MotherContent*>::iterator it=mContents->begin();it!=mContents->end();it++)
	{
		(*it)->printDTD();
	}
}

/**
 * Impl&eacute;mentation de la m&eacute;thode generateRegex de DTDDocument
 */
std::map<std::string, std::string>*  DTDDocument::generateRegex()
{
	std::map<std::string, std::string> * regexMap = new std::map<std::string, std::string>;
	std::list<MotherContent*>::iterator it;
	// parcours de l'ensemble des définitions du fichier
	for( it = mContents->begin(); it != mContents->end(); it++ )
	{
		std::string name = (*it)->getName();
		std::string regex = (*it)->createRegex();
		(*regexMap)[name] = regex;
		// ajout dans la map de la regex liée au nom du contenu (élément ou attribut)
	}
	return regexMap;
}

// //
///////////////////////////////////////////////////////////////////////////////
