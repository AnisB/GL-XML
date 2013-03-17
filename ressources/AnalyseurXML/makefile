
INC=-I../../src/
SRC= ../../src/xml/misc.cpp ../../src/xml/xmldocument.cpp ../../src/xml/xmlcontent.cpp ../../src/xml/xmlattribute.cpp ../../src/xml/element.cpp
all: analyseXML
analyseXML: *.l *.y makefile
	flex -Pxml xml.l
	bison --debug --verbose --defines=xml.tab.h xml.y -p xml
	g++ -g -DYYDEBUG=1 -o analyseXML ${INC} ${SRC} lex.xml.c  xml.tab.c 
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML

