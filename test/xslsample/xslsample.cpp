#include <xml/xmldocument.h>
#include <xsl/xsldocument.h>
#include <parse/parser.h>
int main(int nbArg, char ** args)
{
	XSLDocument newDoc(Parser::parseXML(args[1]),Parser::parseXML(args[2]));
	newDoc.process();
	return 0;
}
