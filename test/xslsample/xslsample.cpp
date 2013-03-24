#include <xml/xmldocument.h>
#include <xsl/xsldocument.h>
#include <parse/parser.h>
int main(int nbArg, char ** args)
{
	XSLDocument newDoc(Parser::parseXML(args[1]).second,Parser::parseXML(args[2]).second);
	newDoc.process();
	return 0;
}
