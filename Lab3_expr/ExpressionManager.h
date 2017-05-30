#include "ExpressionManagerInterface.h"
class ExpressionManager: public ExpressionManagerInterface
{
public:
	ExpressionManager() {}
	virtual ~ExpressionManager() {}
	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string postfixEvaluate(string postfixExpression);
	string infixToPostfix(string infixExpression);
	
private:
	void process_operator(char op);
	int eval_op(char op);
	bool is_operator(char ch) const{
		return OPERATORS.find(ch) != std::string::npos;
	}
	static const std::string OPERATORS;
    std::stack<int> operand_stack;
    std::stack<string> string_stack;
    
    
    int precedence(char op) const {
      return PRECEDENCE[OPERATORS.find(op)];
    }
    static const int PRECEDENCE[];
    #ifdef USEKW
    KW::stack<char> operator_stack;
    #else
    std::stack<char> operator_stack;
    #endif
    std::string postfix;

};