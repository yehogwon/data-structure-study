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
