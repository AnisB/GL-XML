 
#include <xml/xmldocument.h>
#include <parse/parser.h>
#include <parse/checker.h>
#include <dtd/dtddocument.h>

using namespace std;
int main(int argc, char ** argv)
{
	try
	{
		std::pair<string*,XMLDocument*> xmlparseResult = Parser::parseXML(argv[1]);
		DTDDocument* dtdparseResult = Parser::parseDTD(*(xmlparseResult.first));
		std::cout<< Checker::check(xmlparseResult.second,dtdparseResult)<<endl;

	}
	catch(int e)
	{
		cout << "File not found "<<endl;
	}
	return 0;
} 
