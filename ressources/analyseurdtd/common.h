#ifndef COMMON_H
#define COMMON_H

#include <list>
#include <utility>
#include <string>
#include <dtd/cdata.h>
#include <dtd/dtddocument.h>
#include <dtd/uniqueelement.h>
#include <dtd/multipleelement.h>
#include <dtd/dtdattribute.h>
#include <dtd/dtdpcdata.h>
#include <dtd/mothercontent.h>
#include <dtd/declaration.h>
#include <dtd/any.h>
#include <dtd/empty.h>
#include <dtd/dtdcontent.h>

#ifdef DEBUG
#define debug(x) (x)
#else
#define debug(x) ((void) 0)
#endif

#endif
