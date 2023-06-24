#include "calc.hh"

bool Calculator::is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

bool Calculator::is_operand(char c) {
    return c >= '0' && c <= '9';
}

int Calculator::operator_precedence(char c) {
    if (!is_operator(c)) throw std::invalid_argument("Not an operator");
    switch (c) {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(': 
            return 1;
    }
    return -1;
}

std::string Calculator::infix_to_postfix(std::string expression) {
    OperatorStack stack;
    std::string postfix;

    for (char token : expression) {
        if (is_operand(token)) postfix += token;
        else if (is_operator(token)) {
            switch (token) {
                case ')': 
                    while (!stack.empty() && stack.peek() != '(')
                        postfix += stack.pop();
                    break;
                default: // all other operators
                    while (!stack.empty() && operator_precedence(stack.peek()) >= operator_precedence(token))
                        postfix += stack.pop();
                    break;
            }
        } else {
            throw std::invalid_argument("Invalid token");
        }
    }

    // flush the stack to the postfix string
    while (!stack.empty()) postfix += stack.pop();
    
    return postfix;
}

float Calculator::calculate(std::string expression) {
    std::string postfix = infix_to_postfix(expression);
}
