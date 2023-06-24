#ifndef __CALC_HH__
#define __CALC_HH__

#include <string>
#include "stack.hh"

class Calculator {
private: 
    using OperatorStack = LinkedListStack<char>;

    bool is_operator(char c);
    bool is_operand(char c);
    int operator_precedence(char c);

    std::string infix_to_postfix(std::string expression);
public: 
    float calculate(std::string expression);
};

#endif // __CALC_HH__