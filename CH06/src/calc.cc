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

int Calculator::intify(char c) {
    return c - '0';
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
                    stack.pop();
                    break;
                default: // all other operators
                    while (!stack.empty() && operator_precedence(stack.peek()) >= operator_precedence(token))
                        postfix += stack.pop();
                    stack.push(token);
                    break;
            }
        } else throw std::invalid_argument("Invalid token");
    }

    // flush the stack to the postfix string
    while (!stack.empty()) postfix += stack.pop();
    
    return postfix;
}

float Calculator::calculate(std::string expression) {
    OperandStack stack;
    std::string postfix = infix_to_postfix(expression);

    for (char c : postfix) {
        if (is_operand(c)) stack.push(intify(c));
        else if (is_operator(c)) {
            int op1 = stack.pop(), op2 = stack.pop();
            switch (c) {
                case '+': stack.push(op2 + op1); break;
                case '-': stack.push(op2 - op1); break;
                case '*': stack.push(op2 * op1); break;
                case '/': stack.push(op2 / op1); break;
            }
        } else throw std::invalid_argument("Invalid token");
    }

    if (stack.empty()) throw std::invalid_argument("Invalid expression");
    return stack.pop();
}
