#include <iostream>
#include <stdio>
#include "xml.tab.h"
#include "dtd.tab.h"
#include <string>

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
