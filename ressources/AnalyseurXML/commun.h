#ifndef COMMUN_H
#define COMMUN_H

#include <list>
#include <utility>
#include <string>
#include <xml/misc.h>
#include <xml/xmldocument.h>
#include <xml/element.h>
#include <xml/xmlattribute.h>
#include <xml/pcdata.h>

typedef std::pair<std::string,std::string> ElementName;

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif

#endif
