
/**
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 **/

/**
 * file XSLDocument.cpp
 * @author Anis Benyoub (\c benyoub.anis@gmail.com )
 *
 * date 
 *
 * Source file for module XSLDocument
 *
 */


//////////////////////////////////////////////////////////////////////////////
//Includes
#include <xsl/xsldocument.h>
#include <errors.h>
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
XSLDocument::XSLDocument( XMLDocument * xsl, XMLDocument *xml)
{
	mXml=xml;
	mXsl=xsl;
}


/**
 * Destructor.
 */
 XSLDocument::~XSLDocument()
 {
 }


 std::vector<std::string> XSLDocument::split ( std::string &chaine, char c )
 {
 	int size = chaine.size();
 	int r = 0;
 	vector<std::string> v;
 	for (int i = 0; i < size; i++)
 	{
 		if (chaine[i] == c)
 		{
 			v.push_back(chaine.substr(r, i - r));
 			r = i + 1;
 		}
 	}
 	v.push_back(chaine.substr(r, size - r));
 	return v;
 }

/**
* Processes the xml file
*/
std::string XSLDocument::process()
{

	std::list<XMLContent *> theListToHandle;
	std::list<XMLContent *> * theHandlers;
	std::string parseResult="<!DOCTYPE html>";
	// std::cout<<"<!DOCTYPE html>";
	Element * root= mXml->getRoot();
	std::list<XMLContent*>::iterator it = mXsl->getRoot()->getContent()->begin();
	for(;it!=mXsl->getRoot()->getContent()->end();it++)
	{
		// Handling the main template
		if(((*it)->getType()=="xsl:template"))
		{	
			theListToHandle= match((**it)["match"],root);
			theHandlers=(*it)->getContent();
			
		}
		break;		
	}

	for(;it!=mXsl->getRoot()->getContent()->end();it++)
	{
		// Memorising the other templates
		if(((*it)->getType()=="xsl:template"))
		{	
			std::string matchString =(**it)["match"];
			templates[matchString]=(*it);
		}		
	}

	// Launching the interpreter
	for(list<XMLContent*>::iterator that = theHandlers->begin();that!=theHandlers->end();that++)
	{
		parseResult+=handleTemplate(*that,theListToHandle);
	}

	mParse=parseResult;
	return parseResult;
}


std::list<XMLContent*> XSLDocument::match(std::string match, Element * root)
{
	std::list<XMLContent*> listeToReturn;
	if(match[0]=='/')
	{
		if( match.size()>1) 
		{
			if (match[1]=='/')
			{

			    // We got a //
				match[0]=' ';
				std::vector<std::string> table = split(match,'/');
				std::list<XMLContent*> temp = root->getAllContent(table[1]);
				for(int i=2;i!=table.size();i++)
				{
					temp=getListContent(temp,table[i]);
				}
				return temp;
			}
			else
			{
			    // We got a / and some text after
				std::vector<std::string> table = split(match,'/');
				std::list<XMLContent*> temp;
				temp.push_back(root);
				for(int i=1;i!=table.size();i++)
				{
					temp=getListContent(temp,table[i]);
				}
				return temp;

			}
		}
		else
		{
			std::list<XMLContent*> * temp = new std::list<XMLContent*>;
			temp->push_back(root);
			XMLContent * lolil = new Element("","root",new std::list<XMLAttribute*>, temp);
			std::list<XMLContent*> temp2 ;
			temp2.push_back(lolil);		
			return temp2;
		}
	}
	else if (match[0]=='.')
	{
		std::list<XMLContent*> temp;
		temp.push_back(root);
		return temp;
	}
	else
	{
			
		throw NO_MATCH_PARAMETER;
	}
}



/**
* Returns the HTML file
*/
std::string XSLDocument::getParse()
{
	return mParse;
}


std::list<XMLContent*> XSLDocument::getListContent(std::list<XMLContent*> roots, std::string name )
{
	std::list<XMLContent*> lisToReturn;
	for(std::list<XMLContent*>::iterator that=roots.begin();that!=roots.end();that++)
	{
		std::list<XMLContent*> listSons =(*that)->getSonList(name);
		for(std::list<XMLContent*>::iterator it=listSons.begin();it!=listSons.end();it++)
		{
			lisToReturn.push_back(*it);
		}
	}
	return lisToReturn;
}


std::string XSLDocument::handleTemplate(XMLContent * node, std::list<XMLContent*>  theList)
{
	std::string toReturn="";
	if(node->getType()=="xsl:for-each")
	{
		std::string pathToDisplay=(*node)["select"];
		std::vector<std::string> table = split(pathToDisplay,'/');
		std::list<XMLContent*> otherList;
		otherList=theList;
		for(int i=0;i!=table.size();i++)
		{
			otherList=getListContent(otherList,table[i]);
		}
		for(std::list<XMLContent*>::iterator that=otherList.begin();that!=otherList.end();that++)
		{
			for(std::list<XMLContent*>::iterator itis=node->getContent()->begin();itis!=node->getContent()->end();itis++)
			{
				std::list<XMLContent*> togive;
				togive.push_back(*that);
				toReturn+=handleTemplate((*itis),togive);
			}
		}
	}
	else if(node->getType()=="xsl:value-of")
	{
		std::list<XMLContent*> otherList;


		std::string pathToDisplay=(*node)["select"];
		if(pathToDisplay==".")
		{
			otherList=theList;
		}
		else{

			std::vector<std::string> table = split(pathToDisplay,'/');

			otherList=theList;
			for(int i=0;i!=table.size();i++)
			{
				otherList=getListContent(otherList,table[i]);
			}
		}
		for(std::list<XMLContent*>::iterator that=otherList.begin();that!=otherList.end();that++)
		{
			// (*that)->printXML();
			toReturn+=(*that)->getOpen();
			toReturn+=(*that)->getClose();
		}
	}
	else if(node->getType()=="xsl:apply-templates")
	{
		
		if((*node)["select"]!="")
		{

			for(std::list<XMLContent*>::iterator that=theList.begin();that!=theList.end();that++)
			{
				if( (*node)["select"]==(*that)->getType())
				{
					toReturn+=applyTemplateHandle(*that);
				}
			}
		}
		else
		{

			for(std::list<XMLContent*>::iterator that=theList.begin();that!=theList.end();that++)
			{
				toReturn+=applyTemplateHandle(*that);
			}
		}
	}
	else
	{
		// std::cout<<node->getOpen()<<endl;;
		toReturn+=(node->getOpen());
		if((node->getContent()!=NULL) && (node->getContent()->size()>0))
		{

			for(std::list<XMLContent*>::iterator that=node->getContent()->begin();that!=node->getContent()->end();that++)
			{
				toReturn+=handleTemplate((*that),theList);
			}
		}
		// std::cout<<node->getClose()<<endl;
		toReturn+=(node->getClose());
	}
	return toReturn;
}

std::string XSLDocument::applyTemplateHandle(XMLContent * node)
{
	std::string toReturn;
	std::map<string,XMLContent*>::iterator his=templates.find((node)->getType());
	if(his!= templates.end())
	{
		std::list<XMLContent*> * otherList= node->getContent();
		XMLContent * pointer =his->second;
		for(std::list<XMLContent*>::iterator that=pointer->getContent()->begin();that!=pointer->getContent()->end();that++)
		{
			toReturn+=handleTemplate((*that),*otherList);
		}
	}
	else
	{

		toReturn+=node->getOpen();
		if(node->getContent()!=NULL)
		{
			for(std::list<XMLContent*>::iterator that=node->getContent()->begin();that!=node->getContent()->end();that++)
			{
				toReturn+=applyTemplateHandle(*that);
			}
		}
		toReturn+=node->getClose();

	}
	return toReturn;
}
///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
