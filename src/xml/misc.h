#ifndef MISC_H
#define MISC_H
#include <iostream>
#include <list>
class Misc {
	std::string mValue;
	std::list<Misc> *miscs;	

  public:
	Misc(std::string acomment);
	~Misc();
  };
#endif