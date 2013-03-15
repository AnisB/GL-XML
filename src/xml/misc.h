#ifndef MISC_H
#define MISC_H
#include <iostream>
using namespace std;

class Misc {
	string comment;
	list<Misc> *miscs;	

  public:
	Misc(string _comment);
	~Misc();
  };
#endif