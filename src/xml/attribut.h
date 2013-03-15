#ifndef ATTRIBUT_H
#define ATTRIBUT_H
#include <iostream>
using namespace std;

class Attribut {
	string name;
	string value;	

  public:
	Attribut(string _name, string _value);
	~Attribut();
  };
#endif