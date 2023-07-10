#include <iostream>
#include <random>
#include "queue.hh"

const int SIMULATION_TIME = 3600;
const int PURCHASE_TERM = 15;

const int CHEEZE_BURGER_DELAY = 12;
const int BULGOGI_BURGER_DELAY = 15;
const int DOUBLE_BURGER_DELAY = 24;

enum { CHEEZE_BURGER, BULGOGI_BURGER, DOUBLE_BURGER };

using Queue = ArrayQueue<int>;

int main() {
    Queue queue;
    int processing = 0;
    int n_cheeze = 0, n_bulgogi = 0, n_double = 0;

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2);

    for (int sec = 0; sec < SIMULATION_TIME; sec++) {
        if (sec % PURCHASE_TERM == 0) {
            switch (dis(gen)) {
                case CHEEZE_BURGER: 
                    queue.enqueue(CHEEZE_BURGER_DELAY);
                    n_cheeze++;
                    break;
                case BULGOGI_BURGER:
                    queue.enqueue(BULGOGI_BURGER_DELAY);
                    n_bulgogi++;
                    break;
                case DOUBLE_BURGER:
                    queue.enqueue(DOUBLE_BURGER_DELAY);
                    n_double++;
                    break;
            }
        }

        if (processing <= 0 && !queue.empty()) processing = queue.dequeue();
        processing--;
    }

    std::cout << " ====== Simulation Result ====== " << std::endl;
    std::cout << " - Cheeze Burger: " << n_cheeze << std::endl;
    std::cout << " - Bulgogi Burger: " << n_bulgogi << std::endl;
    std::cout << " - Double Burger: " << n_double << std::endl;
    std::cout << " - Total: " << n_cheeze + n_bulgogi + n_double << std::endl;
    std::cout << " - Waiting room size for the simulation: " << HEAP_MAX_LENGTH << std::endl;

    return 0;
}
