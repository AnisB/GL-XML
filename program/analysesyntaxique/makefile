XMLPATH = "../../ressources/AnalyseurXML"
DTDPATH = "../../ressources/AnalyseurDTD"


all: main.o lex.dtd.o lex.xml.o dtd.tab.o xml.tab.o
	g++ main.o lex.dtd.o lex.xml.o dtd.tab.o xml.tab.o -o analysesyntaxique
	
main.o: main.cpp
	g++ -c main.cpp

lex.xml.o: lex.xml.c xml.tab.h
	g++ -c lex.xml.c
dtd.tab.o: dtd.tab.c dtd.tab.h
	g++ -c dtd.tab.c
xml.tab.o: xml.tab.c xml.tab.h
	g++ -c xml.tab.c
lex.dtd.o: lex.dtd.c dtd.tab.h
	g++ -c lex.dtd.c

xml.tab.h: xml.tab.c
lex.xml.c: xml.tab.c
xml.tab.c:
	flex -Pxml xml.l
	bison --debug --verbose --defines=xml.tab.h xml.y -p xml

dtd.tab.h: dtd.tab.c
lex.dtd.c : dtd.tab.c
dtd.tab.c:
	flex -Pdtd dtd.l
	bison --debug --verbose --defines=dtd.tab.h dtd.y -p dtd
	
clear:
	-rm -rf *.tab.c lex.*.c tab.h.* analysesyntaxique