#include "ExprHelper.h"

const std::map<std::string, ExprHelper::expr_op> ExprHelper::string_to_op = {
  {"ALIAS", ExprHelper::OP_ALIAS}, /* Parser-use only */
  {"PATH", ExprHelper::OP_PATH}, /* Parser-use only */
  {"NUM", ExprHelper::OP_NUM}, /* Parser-use only */
  {"INDEX", ExprHelper::OP_INDEX},
  {"+", ExprHelper::OP_ADD},
  {"add", ExprHelper::OP_ADD},
  {"ADD", ExprHelper::OP_ADD},
  {"sqrt", ExprHelper::OP_SQRT},
  {"POW", ExprHelper::OP_POW},
  {"^", ExprHelper::OP_POW},
  {"MAGNITUDE", ExprHelper::OP_MAGN},
  {"magnitude", ExprHelper::OP_MAGN},
  {"pdf", ExprHelper::OP_PDF}
};
  
const std::map<ExprHelper::expr_op, std::string> ExprHelper::op_to_string = {
  {ExprHelper::OP_NULL, "NULL"},
  {ExprHelper::OP_ALIAS, "ALIAS"}, /* Parser-use only */
  {ExprHelper::OP_PATH, "PATH"}, /* Parser-use only */
  {ExprHelper::OP_NUM, "NUM"}, /* Parser-use only */
  {ExprHelper::OP_INDEX, "INDEX"},
  {ExprHelper::OP_ADD, "ADD"},
  {ExprHelper::OP_SQRT, "SQRT"},
  {ExprHelper::OP_POW, "POW"},
  {ExprHelper::OP_MAGN, "MAGNITUDE"},
  {ExprHelper::OP_PDF, "PDF"}
};

std::string ExprHelper::get_op_name(ExprHelper::expr_op op)
{
  return ExprHelper::op_to_string.at(op);
}

ExprHelper::expr_op ExprHelper::get_op(std::string op)
{
  return ExprHelper::string_to_op.at(op);
}
