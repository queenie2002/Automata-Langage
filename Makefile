all: parser

parser.tab.c parser.tab.h:	parser.y
	bison -t -v -d parser.y

lex.yy.c: parser.l parser.tab.h
	flex parser.l

parser: lex.yy.c parser.tab.c parser.tab.h table_of_symbols.c table_of_symbols.h
	gcc -o parser parser.tab.c lex.yy.c table_of_symbols.c table_of_symbols.h

clean:
	rm parser parser.tab.c lex.yy.c parser.tab.h parser.output

test: all
	 ./parser < test.c