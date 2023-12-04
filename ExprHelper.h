#include <map>
#include <tuple>
#include <string>
#include <vector>

class ExprHelper
{
public:
 
  enum expr_op  {
    OP_NULL,
    OP_ALIAS, /* Parser-use only */
    OP_PATH, /* Parser-use only */
    OP_NUM, /* Parser-use only */
    OP_INDEX,
    OP_ADD,
    OP_SQRT,
    OP_POW,
    OP_MAGN,
    OP_PDF
  };

  static std::string get_op_name(expr_op op);
  static expr_op get_op(std::string str);

private:
  const static std::map<std::string, expr_op> string_to_op;
  const static std::map<expr_op, std::string> op_to_string;
};
