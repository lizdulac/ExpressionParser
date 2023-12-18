USE_BISON_3.8 = true
CC = g++
OPT = -std=c++11
ifdef USE_BISON_3.8
BISON = /usr/local/Cellar/bison/3.8.2/bin/bison
PARSER = parser.y
#PARSER = parser-cp.y
#PARSER = parser-new.y
else
BISON = /usr/bin/bison
PARSER = parser.y
endif
simple-c: parser.cpp
	$(CC) $(OPT) $^ -o $@

parser.h parser.cpp: $(PARSER)
	$(BISON) --version
	$(BISON) -d -v --defines=parser.h -o parser.cpp $(PARSER)
ifndef USE_BISON_3.8
	echo "\n#include \"ASTNode.h\"\n\nASTNode* parse_expression(const char* input);" >> parser.h
endif

clean:
	rm *.o *.hh *~ lexer.cpp lexer.h parser.cpp parser.h parser.hpp parser.output simple-c
