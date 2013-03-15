#include <string>

#include "content.h"

class CData : public Content
{
public:
	CData(std::string* content);
	virtual ~CData();

	void setContent(std::string* content);
	std::string* getContent();

	

protected:
	std::string* m_content;
};