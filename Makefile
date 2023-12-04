USE_BISON_3.8 = 
#USE_BISON_3.8 = true
CC = g++
OPT = -std=c++11
OLD-OPT = -O3 -std=c11
ifdef USE_BISON_3.8
#BISON = /usr/local/Cellar/bison/3.8.2/bin/bison
#PARSER = parser-cp.y
else
BISON = /usr/bin/bison
PARSER = parser.y
endif
simple-c: driver.cpp lexer.cpp parser.cpp ASTNode.cpp ExprHelper.cpp
	$(CC) $(OPT) $^ -o $@

lexer.h lexer.cpp: lexer.l
	flex --header-file=lexer.h -o lexer.cpp lexer.l 

parser.h parser.cpp: parser.y
	$(BISON) -d -v -o parser.cpp $(PARSER)
ifndef USE_BISON_3.8
	echo "\n#include \"ASTNode.h\"\n\nASTNode* parse_expression(const char* input);" >> parser.h
endif
#	echo "\n#include <vector>\n#include<string>\n\nstd::vector<std::string> parse_expression(const char* input);" >> parser.hpp

clean:
	rm *.o *.hh *~ lexer.cpp lexer.h parser.cpp parser.h parser.hpp parser.output simple-c
