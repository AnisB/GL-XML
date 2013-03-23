
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
	mXsl->displayAsXMLFormat();
	std::string htmlFile="<!DOCTYPE html>";
	Element * root= mXml->getRoot();
	std::list<XMLContent*>::iterator it = mXsl->getRoot()->getContent()->begin();
	for(;it!=mXsl->getRoot()->getContent()->end();it++)
	{
		cout<<"in"<<endl;
		if(((*it)->getType()=="xsl:template"))
		{	
			std::list<XMLContent*> listToHandle = match((**it)["match"],root);
			cout<<*it<<endl;
			handleTemplate(*it,listToHandle);
		}
		cout<<"out"<<endl;
		
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


std::string XSLDocument::handleTemplate(XMLContent * node, std::list<XMLContent*>  theList)
{
	std::cout<<"hi"<<endl;
	std::string toReturn="";
	if(node->getType()=="xsl:for-each")
	{

	}
	else
	{
		std::cout<<"hi2"<<node->getOpen()<<node->getContent()<<endl;
		toReturn+=(node->getOpen());

		for(std::list<XMLContent*>::iterator that=node->getContent()->begin();that!=node->getContent()->end();that++)
		{
			cout<<"lol"<<endl;
		}
		std::cout<<"after"<<endl;
		toReturn+=(node->getClose());

	}
	return toReturn;
}


///////////////////////////////////////////////////////////////////////////////
// Interface - public :

///////////////////////////////////////////////////////////////////////////////
// Implementation of inline functimyCameraons //



// //
///////////////////////////////////////////////////////////////////////////////
