all: analyseDTD
analyseDTD: *.l *.y makefile
	flex -Pdtd dtd.l
	bison --debug --verbose --defines=yy.tab.h dtd.y -p dtd
	g++ -g -DYYDEBUG=1 -o analyseDTD  lex.dtd.c dtd.tab.c 
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseDTD

