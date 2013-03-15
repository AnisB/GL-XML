#ifndef XMLAttribute_H
#define XMLAttribute_H
#include <iostream>
using namespace std;

class XMLAttribute {
	string name;
	string value;	

  public:
	XMLAttribute(string _name, string _value);
	~XMLAttribute();
  };
#endif