#ifndef __TREE_CALC_HH__
#define __TREE_CALC_HH__

#include <string>
#include "stack.hh"
#include "binary.tree.hh"
#include "binary.tree.traverse.hh"

bool is_operator(char c);
bool is_numeric(char c);
bool is_dp(char c);
float numberify(const std::string::const_iterator &begin, const std::string::const_iterator &end);
int operator_precedence(char c);

std::string infix_to_postfix(const std::string &expression);

float calculate(const nodeptr<*> &root);

#endif // __TREE_CALC_HH__