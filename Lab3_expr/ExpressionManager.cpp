#include "ExpressionManager.h"  
#include <sstream>
#include <cctype>

const string OPEN = "([{";
const string CLOSE = ")]}";
const std::string ExpressionManager::OPERATORS = "+-*/%()";

const int ExpressionManager::PRECEDENCE[] = { 1, 1, 2, 2, 2, -1, -1 };

bool is_open(char ch) {
    return OPEN.find(ch) != string::npos;
}
bool is_close(char ch) {
    return CLOSE.find(ch) != string::npos;
}
bool ExpressionManager::isBalanced(string expression) {
    cout << "In isBalanced expression "<<expression<<endl;
    
    stack<char> s;
    bool balanced = true;
    for (string::const_iterator iter = expression.begin();
     balanced && (iter != expression.end());
     iter++) {
        char next_ch = *iter;
        if (is_open(next_ch)) {
            s.push(next_ch);
        } else if (is_close(next_ch)) {
            if (s.empty()) {
                balanced = false;
            } else {
                char top_ch = s.top();
                s.pop();
                balanced = 
                 OPEN.find(top_ch) == CLOSE.find(next_ch);
            }
        }
    }
    return balanced && s.empty();
}
string ExpressionManager::postfixEvaluate(string postfixExpression){
    
  cout << "In postfixEvaluate "<< postfixExpression << endl;
  while (!operand_stack.empty())
    operand_stack.pop();

  istringstream tokens(postfixExpression);
  char next_char;
  while (tokens >> next_char) {
    if (isdigit(next_char)) {
      tokens.putback(next_char);
      int value;
      tokens >> value;
      operand_stack.push(value);
      
    } else if (is_operator(next_char)) {
      int result;
      try {
        result = eval_op(next_char);
      }
      catch(int which) {
          cout << "not enough operands";
          return("invalid");
      }
      operand_stack.push(result);
    } else {
      cout << "not digit or operand";
      return("invalid");
    }
  }
  if (!operand_stack.empty()) {
    string answer = to_string(operand_stack.top());
    operand_stack.pop();
    if (operand_stack.empty()) {
              if (answer== to_string(-111)){
          return "invalid";
        }
      return answer;
    } else {
      cout << "at end stack not empty";
      return("invalid");
    }
  } else {
    cout << "at end answer not on stack";
    return("invalid");
  }

}
int ExpressionManager::eval_op(char op) {
  if (operand_stack.empty()) 
    throw 1;
  int rhs = operand_stack.top();
  operand_stack.pop();
  if (operand_stack.empty())
    throw 2;
  int lhs = operand_stack.top();
  operand_stack.pop();
  int result = 0;
  if (op == '/' && rhs == 0){
    return -111;
  }
  switch(op) {
  case '+' : result = lhs + rhs;
             break;
  case '-' : result = lhs - rhs;
             break;
  case '*' : result = lhs * rhs;
             break;
  case '/' : result = lhs / rhs;
             break;
  case '%' : result = lhs % rhs;
             break;
  }
  return result;
}

string ExpressionManager::postfixToInfix(string postfixExpression){
	    cout << "In postfixToInfix"<<endl;
	    
	        while (string_stack.size() !=0){
          string_stack.pop(); 
         }
	    
  istringstream tokens(postfixExpression);
  char next_char;
  while (tokens >> next_char) {
    if (isalpha(next_char)){
      return "invalid";
    }
    if (isdigit(next_char)) {
      tokens.putback(next_char);
      int value;
      tokens >> value;
      string_stack.push(std::to_string(value));
    }
    else if (is_operator(next_char )) {
        if (string_stack.size() < 2){
          cout << string_stack.size();
        return "invalid";
      }
        string rhs = string_stack.top();
        string_stack.pop();
        
        string lhs = string_stack.top();
        string_stack.pop();
        string result;
        
        switch(next_char) {
            case '+' : result = "( " + lhs + " " + "+" + " " + rhs + " )";
                        break;
            case '-' : result = "( " + lhs + " " + "-" + " " + rhs + " )";
                        break;
            case '*' : result = "( " + lhs + " " + "*" + " " + rhs + " )";
                        break;
            case '/' : result = "( " + lhs + " " + "/" + " " + rhs + " )";
                        break;
            case '%' : result = "( " + lhs + " " + "%" + " " + rhs + " )";
                        break;
        }
          string_stack.push(result);
      }
    }
    // check size if 1 return .top
    string temp = string_stack.top();
     if (string_stack.size() == 1){
      cout << string_stack.size() << endl;
        return temp;
      }
      else{
         return "invalid";
      }
  }

string ExpressionManager::infixToPostfix(string infixExpression){
  postfix = "";
  if (infixExpression == "+" || infixExpression  == "-" || infixExpression  == "*" || infixExpression  == "/"){
    return "invalid";
  }
  while (!operator_stack.empty()) 
    operator_stack.pop();
  istringstream infix_tokens(infixExpression);
  string next_token;
  
  
  
  while(infix_tokens >> next_token) {
    if (isdigit(next_token[0])) {
      postfix += next_token;
      postfix += " ";
    } else if (is_operator(next_token[0])  ) {
      process_operator(next_token[0]);
    } else {
      return "invalid";
       throw "Unexpected Character Encountered";
     }
  } // End while
  // Pop any remaining operators and append them to postfix
  while (!operator_stack.empty()) {
    char op = operator_stack.top();
    operator_stack.pop();
    if (op == '(') {
      return "invalid";
      throw "Unmatched open parenthesis";
    }
    postfix += op;
    postfix += " ";
  }
  if(postfixToInfix(postfix) == "invalid"){
    return "invalid";
  }
  return postfix;
}


void ExpressionManager::process_operator(char op) {
  if (operator_stack.empty() || (op == '(')) {
    if (op == ')')
    
      throw "Unmatched close parenthesis";
    operator_stack.push(op);
  } else {
    if (precedence(op) > precedence(operator_stack.top())) {
      operator_stack.push(op);
    } else {
      // Pop all stacked operators with equal
      // or higher precedence than op.
      while (!operator_stack.empty()
             && (operator_stack.top() != '(')
             && (precedence(op) <= precedence(operator_stack.top()))) {
        postfix += operator_stack.top();
        postfix += " ";
        operator_stack.pop();
      }
      // assert: Operator stack is empty or 
      //         top of stack is '(' or current
      //         operator precedence > top of stack operator
      //         precedence;
      if (op == ')') {
        if (!operator_stack.empty() 
            && (operator_stack.top() == '(')) {
          operator_stack.pop();
        } else {
          throw "Unmatched close parentheses";
        }
      }
      else {
        operator_stack.push(op);
      }
    }
  }
}