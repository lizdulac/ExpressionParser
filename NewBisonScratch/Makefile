USE_BISON_3.8 = true
CC = g++
OUTPUT_DIR = ./pregen-source
PARSER_SOURCE = ./
OPT = -std=c++11 -I$(OUTPUT_DIR) -I$(PARSER_SOURCE)
ifdef USE_BISON_3.8
BISON = /usr/local/Cellar/bison/3.8.2/bin/bison
PARSER = parser.y
#PARSER = parser-cp.y
#PARSER = parser-new.y
else
BISON = /usr/bin/bison
PARSER = parser.y
endif

$(OUTPUT_DIR)/simple-c: driver.cpp $(OUTPUT_DIR)/lexer.cpp $(OUTPUT_DIR)/parser.cpp
	$(CC) $(OPT) $^ -o $(OUTPUT_DIR)/$@

$(OUTPUT_DIR)/lexer.h $(OUTPUT_DIR)/lexer.cpp: lexer.l
	flex --header-file=$(OUTPUT_DIR)/lexer.h -o $(OUTPUT_DIR)/lexer.cpp lexer.l 

$(OUTPUT_DIR)/parser.h $(OUTPUT_DIR)/parser.cpp: $(PARSER)
	$(BISON) --version
	$(BISON) -d -v --defines=$(OUTPUT_DIR)/parser.h -o $(OUTPUT_DIR)/parser.cpp $(PARSER)
ifndef USE_BISON_3.8
	echo "\n#include \"ASTNode.h\"\n\nASTNode* parse_expression(const char* input);" >> parser.h
endif

clean:
	rm *.o *~ lexer.cpp lexer.h parser.cpp parser.h parser.hpp parser.output simple-c
