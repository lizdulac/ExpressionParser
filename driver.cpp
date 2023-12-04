#include <string>
#include <iostream>
#include "parser.h"
//#include "ASTNode.h"

int main(int argc, char **argv) {
  std::string str = "x:sim/Ux\ny:sim/Uy\npdf(x^2,y)";
  //std::string str = "x:sim/Ux \ny:sim/Uy \nz:sim/Uz \nsqrt(x+y+z)";
  //std::string str = "x:/path-2/var_x[0,::2,:10:]\ny:/path/to/y\nz:/path/z\nx+y+z";
  //std::string str = "x:/path-2/var_x[0,::2,:10:]\ny:/path_to/var-y\n(x+y)+z[::,10]+(y+'this_is/a/path')+magnitude(x)\n";
  //std::string str = "(x+y)+z+y\nx:/path-2/var_x\ny:/path_to/var-y";
  const char* exp = str.c_str();
  std::cout << "Input expression: " << exp << std::endl;

  ASTNode* parsed_expr = parse_expression(exp);
  parsed_expr->printpretty();
  
  /*
  ASTNode* parsed_expr = parse_expression(exp);

  std::cout << "Driver.cpp: ASTNode returned. Pretty Print:" << std::endl;
  parsed_expr->printpretty();
  
  std::cout << "Driver.cpp: Finished. Deleting ASTNode." << std::endl;
  delete parsed_expr;

  std::cout << "Driver.cpp: ASTNode should be null:" << parsed_expr << std::endl;
  parsed_expr->printpretty();
  */
  /*
  std::vector<std::string> vars = parse_expression(exp);
    std::cout << "Returned vector of strings:" << std::endl;
    for (std::string s: vars)
      {
        std::cout << "   " << s << std::endl;
      }
  ASTNode<double>* expr = static_cast<ASTNode<double>*>(parse_expression(exp));
  std::cout << "ASTNode has been parsed. Parse tree:" << std::endl;
  std::cout << expr->printpretty("");
  */
  return 0;
}
