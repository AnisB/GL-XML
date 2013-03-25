#include <xml/xmldocument.h>
#include <xsl/xsldocument.h>
#include <parse/parser.h>

using namespace std;
int main(int nbArg, char ** args)
{
	std::pair<string*,XMLDocument *> pairResult =Parser::parseXML(args[1]);
	std::pair<string*,XMLDocument *> pairResult2 =Parser::parseXML(args[2]);
	XSLDocument newDoc(Parser::parseXML(args[1]).second,Parser::parseXML(args[2]).second);
	newDoc.process();
	if(pairResult.first!=NULL)
	{
		delete pairResult.first;
	}
	delete pairResult.second;	
	if(pairResult2.first!=NULL)
	{
		delete pairResult2.first;
	}
	delete pairResult2.second;
	return 0;
}
