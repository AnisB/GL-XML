#include "PCData"

PCData::PCData(std::string value)
{
	mValue=value;
}

PCData::~PCData()
{
	//Nothing to do
}

void PCData::setValue(std::string value)
{
	mValue=value;
}

std::string PCData::getValue()
{
	return mValue;
}