#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Expression.h"

/*****************************************/


class ASTNode
{
public:
  ASTNode();
  ASTNode(ExprHelper::expr_op);
  ASTNode(ExprHelper::expr_op, const char *a);
  ASTNode(ExprHelper::expr_op, double val);
  ASTNode(ExprHelper::expr_op, ASTNode *e);
  ASTNode(ExprHelper::expr_op, ASTNode *e, const char *i);
  ASTNode(ExprHelper::expr_op, ASTNode *e1, ASTNode *e2);

  // Copy constructor
  ASTNode(const ASTNode &e);

  ~ASTNode();

  static std::pair<std::string, std::string> lookup_var(const std::string var_alias);
  static std::string lookup_var_path(const std::string var_alias);
  static std::string lookup_var_indices(const std::string var_alias);
  static void add_lookup_entry(const std::string alias, const std::string var_name, const std::string indices);
  
  void add_subexpr(ASTNode* e);
  void add_back_subexpr(ASTNode* e, size_t i);
  void extend_subexprs(size_t n);
  void infer_type();
  void printpretty(std::string indent = "");
  void to_expr(Expression*);

  //private:
  ExprHelper::expr_op operation;
  std::string alias;
  std::string indices;
  double value;
  std::vector<ASTNode*> sub_expr;

  static std::map<std::string, std::pair<std::string, std::string> > var_lookup;
  // DEBUGGING
  static int num_expr;
};
