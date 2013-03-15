XMLPATH = "../../ressources/AnalyseurXML"
DTDPATH = "../../ressources/AnalyseurDTD"


all: main.o lex.dtd.o lex.xml.o dtd.tab.o xml.tab.o
	g++ main.o lex.dtd.o lex.xml.o dtd.tab.o xml.tab.o -o analysesyntaxique
	
main.o: main.cpp
	g++ -c main.cpp

lex.xml.o: xml.tab.c
	g++ -c xml.tab.c
dtd.tab.o: dtd.tab.c
	g++ -c dtd.tab.c
xml.tab.o: xml.tab.c
	g++ -cxml.tab.c
lex.dtd.o: lex.dtd.c
	g++ -c lex.dtd.c

lex.xml.c: xml.tab.c
xml.tab.c:
	flex -Pxml xml.l
	bison --debug --verbose --defines=xml.tab.h xml.y -p xml

lex.dtd.c : dtd.tab.c
dtd.tab.c:
	flex -Pdtd dtd.l
	bison --debug --verbose --defines=dtd.tab.h dtd.y -p dtd