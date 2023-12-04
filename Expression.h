#include <tuple>
#include <string>
#include <vector>

#include "ExprHelper.h"

struct OpInfo
{
  ExprHelper::expr_op operation;
  std::vector<std::tuple<size_t, size_t, size_t> > indices;
  double constant;
};

class Expression
{
public:
  std::vector<std::tuple<Expression*, std::string>> sub_exprs;
  OpInfo detail;

  Expression() {};
  Expression(ExprHelper::expr_op o) : detail({o,{},0}) {}
  Expression(ExprHelper::expr_op o, double c) : detail({o,{},0}) {}
  Expression(std::vector<std::tuple<size_t, size_t, size_t> > indices)
    : detail({ExprHelper::OP_INDEX, indices,0}) {}

  void set_base(double c)
  {
    detail.constant = c;
  }
  
  void add_child(Expression *exp)
  {
    sub_exprs.push_back({exp, ""});
  }

  void add_child(std::string var)
  {
    sub_exprs.push_back({nullptr, var});
  }

  void prettyprint(std::string indent = "")
  {
    std::cout << indent << "- Print Expression: ";
    std::cout << ExprHelper::get_op_name(detail.operation) << std::endl;
    std::cout << indent << "  constant (base): " << detail.constant << std::endl;
    std::cout << indent << "  children: " << sub_exprs.size() << std::endl;

    for (std::tuple<Expression*, std::string> t: sub_exprs)
      {
	if (std::get<0>(t) != nullptr)
	  {
	    std::get<0>(t)->prettyprint(indent + "\t");
	  }
	else
	  {
	    std::cout << indent << "\t- string: " << std::get<1>(t) << std::endl;
	  }
      }
  }
};
