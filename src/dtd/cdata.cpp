#include <string>

#include "cdata.h"

using namespace std;

CData::CData(std::string* content) : DTDContent(), m_content(content)
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
