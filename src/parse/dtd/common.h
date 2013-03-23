#ifndef COMMUN_H
#define COMMUN_H

#include <list>
#include <utility>
#include <string>
#include <dtd/dtddocument.h>
#include <dtd/mothercontent.h>
#include <dtd/multipleelement.h>
#include <dtd/empty.h>
#include <dtd/any.h>
#include <dtd/dtdpcdata.h>
#include <dtd/dtdattribute.h>

typedef std::pair<std::string,std::string> ElementName;

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif

#endif
