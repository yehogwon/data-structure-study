#include <iostream>

// Note that this algorithm can be improved by using memoization.
int fibo(int n) {
    if (n == 1) return 0;
    else if (n == 2) return 1;
    else return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    std::cout << "How many numbers? ";
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cout << i << "th Fibonacci number: " << fibo(i) << std::endl;
    return 0;
}
