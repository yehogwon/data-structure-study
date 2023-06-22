#include <iostream>

void hanoi(int n, char from, char by, char to) {
    if (n == 0) return;
    hanoi(n - 1, from, to, by);
    std::cout << "DISK " << n << " ::: " << from << " -> " << to << std::endl;
    hanoi(n - 1, by, from, to);
}

int main() {
    int n;

    std::cout << "The number of disks? ";
    std::cin >> n;

    std::cout << "We denote the three pegs as A, B, and C." << std::endl;
    hanoi(n, 'A', 'B', 'C');

    return 0;
}
