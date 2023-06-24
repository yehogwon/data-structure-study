#ifndef __CALC_HH__
#define __CALC_HH__

#include <string>
#include "stack.hh"

class Calculator {
private: 
    template <typename T>
    using Stack = LinkedListStack<T>;

    using OperatorStack = Stack<char>;
    using OperandStack = Stack<int>;

    bool is_operator(char c);
    bool is_operand(char c);
    int operator_precedence(char c);
    int intify(char c);

    std::string infix_to_postfix(std::string expression);
public: 
    float calculate(std::string expression);
};

#endif // __CALC_HH__