INC=-I../../src/
SRC= ../../src/dtd/*.cpp

all: analyseDTD
analyseDTD: *.l *.y makefile
	flex -Pdtd dtd.l
	bison --debug --verbose --defines=dtd.tab.h dtd.y -p dtd
	g++ -g -DYYDEBUG=1 -o analyseDTD ${INC} ${SRC} lex.dtd.c dtd.tab.c 
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseDTD

