#include <iostream>
#include "calc.hh"

int main() {
    Calculator calculator;
    
    std::string expressions[] = {
        "1+2*3", 
        "(1+2)*3", 
        "((1-2)+3)*(5-2)" // FIXME: this case causes an exception: "std::out_of_range: The stack is empty."
    };

    std::cout << expressions[0] << " = " << calculator.calculate(expressions[0]) << "\n";
    std::cout << expressions[1] << " = " << calculator.calculate(expressions[1]) << "\n";
    std::cout << expressions[2] << " = " << calculator.calculate(expressions[2]) << "\n";

    return 0;
}
