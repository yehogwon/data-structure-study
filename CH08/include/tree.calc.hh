#ifndef __TREE_CALC_HH__
#define __TREE_CALC_HH__

#include <string>
#include <vector>
#include <stdexcept>
#include "stack.hh"
#include "binary.tree.hh"
#include "binary.tree.traverse.hh"

using OperatorStack = LinkedListStack<char>;
using TreeStack = LinkedListStack<nodeptr<std::string>>;

bool is_operator(char c);
int operator_precedence(char c);

bool is_numeric(char c);
bool is_dp(char c);
bool is_float(char c);

std::string stringify(char c);
int intify(char c);
float numberify(const std::string::const_iterator &begin, const std::string::const_iterator &end);

std::vector<std::string> infix_to_postfix(const std::string &expression);
nodeptr<std::string> postfix_to_tree(const std::vector<std::string> &expression);
// float calculate(const nodeptr<?> &root);

#endif // __TREE_CALC_HH__