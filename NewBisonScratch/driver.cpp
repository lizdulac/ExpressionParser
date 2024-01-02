#include <string>
#include <iostream>
#include "ASTNode.h"

int
main (int argc, char *argv[])
{
  ASTNode drv;
  char* str_expr = "one := 1\ntwo := 2\nthree := 3\n(one + two * three) * two * three";
  std::cout << "Parse input: " << str_expr << std::endl;

  int result = drv.parse(str_expr);

  std::cout << "Result: " << result << std::endl;
  
  return 0;
}
