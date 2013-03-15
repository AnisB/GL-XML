#include <string>

#include cdata.h"

using namespace std;

CData::CData(std::string* content) : Content(), m_content(content)
{
}

CData::~CData()
{
}

void CData::setContent(string* content)
{
	m_content = content;
}

string* CData::getContent()
{
	return m_content;
}
