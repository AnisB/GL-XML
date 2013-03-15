#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

extern FILE * xmlin;
int xmlparse(string **);

int main(int argc, char ** argv)
{
	FILE * file;
	file = fopen(argv[0], "r");
	if(!file) {
		return -1;
	}
	string * nomdtd;
	xmlin = file;
	xmlparse(&nomdtd);
	return 0;
} 
