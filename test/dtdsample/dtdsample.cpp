#include <parse/parser.h>
#include <iostream>
using namespace std;
int main(int nb, char** args)
{
	if(nb>0)
	{
		try
		{
			DTDDocument* machin =Parser::parseDTD(args[1]);
			machin->displayAsDTDFormat();
			delete machin;
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
