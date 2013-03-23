
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
#include "xsldocument.h"
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
	std::string htmlFile="<!DOCTYPE html>";
	std::cout<<"<!DOCTYPE html>"<<std::endl;
	Element * root= mXml->getRoot();
	std::list<XMLContent*>::iterator it = mXsl->getRoot()->getContent()->begin();
	for(;it!=mXsl->getRoot()->getContent()->end();it++)
	{

		if(((*it)->getType()=="xsl:template"))
		{	
			theListToHandle= match((**it)["match"],root);
			theHandlers=(*it)->getContent();
			// for(list<XMLContent*>::iterator that = (*it)->getContent()->begin();that!=(*it)->getContent()->end();that++)
			// {
			// 	handleTemplate(*that,listToHandle,false);
			// }
			
		}
		break;		
	}

	for(;it!=mXsl->getRoot()->getContent()->end();it++)
	{
		if(((*it)->getType()=="xsl:template"))
		{	
			std::string matchString =(**it)["match"];
			// std::cout<<"Adding "<<matchString<<endl;
			templates[matchString]=(*it);
		}		
	}

	for(list<XMLContent*>::iterator that = theHandlers->begin();that!=theHandlers->end();that++)
	{
		handleTemplate(*that,theListToHandle,false);
	}
	return htmlFile;
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
			listeToReturn.push_back(root);
			return listeToReturn;
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
		std::cout<<"Error"<<std::endl;		
		//throw 69;
	}
}



/**
* Returns the HTML file
*/
std::string XSLDocument::getHTML()
{
	return "";
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


std::string XSLDocument::handleTemplate(XMLContent * node, std::list<XMLContent*>  theList, bool shouldHT)
{
	// std::cout<<"I am handeling a template "<<node->getType()<<endl;
	std::string toReturn="";
	if(node->getType()=="xsl:for-each")
	{
		std::string pathToDisplay=(*node)["select"];
		std::vector<std::string> table = split(pathToDisplay,'/');
		std::list<XMLContent*> otherList;
		otherList=theList;
		for(int i=1;i!=table.size();i++)
		{
			otherList=getListContent(otherList,table[i]);
		}
		for(std::list<XMLContent*>::iterator that=otherList.begin();that!=otherList.end();that++)
		{
			for(std::list<XMLContent*>::iterator itis=node->getContent()->begin();itis!=node->getContent()->end();itis++)
			{
				std::list<XMLContent*> togive;
				togive.push_back(*that);
				handleTemplate((*itis),togive,shouldHT);
			}
		}
	}
	else if(node->getType()=="xsl:value-of")
	{
		std::list<XMLContent*> otherList;


		std::string pathToDisplay=(*node)["select"];
		// std::cout<<"On rencontre un value of"<<pathToDisplay<<endl;
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
		for(std::list<XMLContent*>::iterator it=theList.begin();it!=theList.end();it++)
		{

			// std::cout<<"On a"<<(*it)->getType();
		}

		for(std::list<XMLContent*>::iterator that=otherList.begin();that!=otherList.end();that++)
		{
			(*that)->printXML();
		}
	}
	else if(node->getType()=="xsl:apply-templates")
	{
		// std::cout<<"I got an apply template "<<node->getType()<<endl;
		
		if((*node)["select"]!="")
		{
			// std::cout<<"The match is'nt nil "<<node->getType()<<endl;

			for(std::list<XMLContent*>::iterator that=theList.begin();that!=theList.end();that++)
			{
				if( (*node)["select"]==(*that)->getType())
				{
			//std::cout<<"Looking if there is a template for "<<(*that)->getType()<<endl;
					applyTemplateHandle(*that);
				}
			}
		}
		else
		{
			// std::cout<<"The match is nil "<<node->getType()<<endl;

			for(std::list<XMLContent*>::iterator that=theList.begin();that!=theList.end();that++)
			{
				applyTemplateHandle(*that);
			}
		}
	}
	else
	{
		// std::cout<<"here"<<endl;
		std::cout<<node->getOpen()<<endl;;
		toReturn+=(node->getOpen());
		// if (!shouldHT)
		// {

		if((node->getContent()!=NULL) && (node->getContent()->size()>0))
		{
			// std::cout<<"got sons"<<(*node->getContent()->begin())<<endl;

			for(std::list<XMLContent*>::iterator that=node->getContent()->begin();that!=node->getContent()->end();that++)
			{
				// std::cout<<"Handeling sons"<<endl;
				handleTemplate((*that),theList,shouldHT);
			}
		}
		std::cout<<node->getClose()<<endl;
		toReturn+=(node->getClose());
	}
	return toReturn;
}

std::string XSLDocument::applyTemplateHandle(XMLContent * node)
{
	// std::cout<<"Looking if there is a template for "<<(node)->getType()<<endl;
	std::map<string,XMLContent*>::iterator his=templates.find((node)->getType());
	if(his!= templates.end())
	{
		// std::cout<<"Prochain Objet "<<(node)->getType()<<", il a"<<endl;
		for(std::list<XMLContent*>::iterator that=node->getContent()->begin();that!=node->getContent()->end();that++)
		{
			// std::cout<<"Ses fils sont"<<(*that)->getType()<<endl;
		}

		std::list<XMLContent*> * otherList= node->getContent();
		XMLContent * pointer =his->second;
		for(std::list<XMLContent*>::iterator that=pointer->getContent()->begin();that!=pointer->getContent()->end();that++)
		{
			// std::cout<<"Giving child of "<<node->getType()<<"to "<<(*that)->getType()<<endl;
			handleTemplate((*that),*otherList,true);
		}
	}
	else
	{

		std::cout<<node->getOpen();

		if(node->getContent()!=NULL)
		{
			// std::cout<<"Content isn't nil"<<std::endl;
			for(std::list<XMLContent*>::iterator that=node->getContent()->begin();that!=node->getContent()->end();that++)
			{
				applyTemplateHandle(*that);
			}
		}
		std::cout<<node->getClose();

	}
	return "";
}
///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
