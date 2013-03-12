#include "content.h"
#include <list>

class PCData : public Content
{
public:
	PCData(arguments);
	~PCData();
	void setValue(std::string value);

protected:
	std:string mValue;

};