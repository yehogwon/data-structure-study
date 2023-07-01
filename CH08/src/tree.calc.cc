#include "tree.calc.hh"

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

int operator_precedence(char c) {
    if (!is_operator(c)) throw std::invalid_argument("Not an operator");
    switch (c) {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(': 
        case ')':
            return 1;
    }
    return -1;
}

bool is_numeric(char c) {
    return c >= '0' && c <= '9';
}

bool is_dp(char c) {
    return c == '.';
}

bool is_float(char c) {
    return is_numeric(c) || is_dp(c);
}

int intify(char c) {
    return c - '0';
}

std::string stringify(char c) {
    return std::string(1, c);
}

float numberify(const std::string::const_iterator &begin, const std::string::const_iterator &end) {
    float number = 0;
    int decimal = 0;
    for (auto it = begin; it != end && is_float(*it); it++) {
        if (is_dp(*it)) {
            if (decimal) throw std::invalid_argument("Invalid number");
            decimal = 1;
            continue;
        }

        if (is_numeric(*it)) {
            if (decimal) {
                decimal *= 10;
                number += intify(*it) / (decimal * 1.0);
            } else {
                number *= 10;
                number += intify(*it);
            }
        }
    }
    return number;
}

std::vector<std::string> infix_to_postfix(const std::string &expression) {
    OperatorStack stack;
    std::vector<std::string> postfix;

    std::string cur = "";
    for (int i = 0; i < expression.size(); i++) {
        char token = expression[i];
        if (is_float(token)) {
            cur += token;
        } else if (is_operator(token)) {
            if (cur != "") {
                postfix.push_back(cur);
                cur = "";
            }
            switch (token) {
                case '(': 
                    stack.push(token);
                    break;
                case ')': 
                    while (!stack.empty() && stack.peek() != '(')
                        postfix.push_back(stringify(stack.pop()));
                    stack.pop();
                    break;
                default: // all other operators
                    while (!stack.empty() && operator_precedence(stack.peek()) >= operator_precedence(token))
                        postfix.push_back(stringify(stack.pop()));
                    stack.push(token);
                    break;
            }
        } else throw std::invalid_argument(std::string("Invalid token: ") + token);
    }
    if (cur != "") {
        postfix.push_back(cur);
        cur = "";
    }

    while (!stack.empty()) postfix.push_back(stringify(stack.pop()));
    
    return postfix;
}

nodeptr<std::string> postfix_to_tree(const std::vector<std::string> &expression) {
    TreeStack stack;

    for (const std::string &token : expression) {
        nodeptr<std::string> ptr = new node<std::string>(token);
        if (is_operator(token[0])) {
            nodeptr<std::string> right_ = stack.pop(), left_ = stack.pop();
            ptr->left = left_;
            ptr->right = right_;
        }
        stack.push(ptr);
    }

    return stack.pop();
}

float evaluate(nodeptr<std::string> root) {
    if (root->left == nullptr && root->right == nullptr) return numberify(root->data.begin(), root->data.end());

    float op1 = evaluate(root->left), op2 = evaluate(root->right);
    switch (root->data[0]) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default: throw std::invalid_argument(std::string("Invalid operator: ") + root->data[0]);
    }
}
