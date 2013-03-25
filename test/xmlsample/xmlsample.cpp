
#include <xml/xmldocument.h>
#include <parse/parser.h>
#include <iostream>
using namespace std;
int main(int nb, char** args)
{
	if(nb>0)
	{
		try
		{
			std::pair<std::string*,XMLDocument*> machin =Parser::parseXML(args[1]);
			machin.second->displayAsXMLFormat();
			if(machin.first!=NULL)
				delete machin.first;
			delete machin.second;
		}
		catch(int e)
		{
			cerr<<"An error occured"<<endl;
			return -1;
		}
	}
	else
	{
		cerr<<"No input file"<<endl;
	}
	return 0;
}
