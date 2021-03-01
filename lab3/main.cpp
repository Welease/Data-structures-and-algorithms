#include <iostream>
#include "DinamicQueue.h"
int main() {
    t_queue *queue = getQueue();
    std::string input;
    while (1) {
        std::cout << BLUE << "Choose option:\n" <<
                  "1 - check empty queue or not\n" <<
                  "2 - push new element to queue\n" <<
                  "3 - pop element from queue\n" <<
                  "4 - print all data from queue\n" <<
                  "5 - get queue's size\n" <<
                  "6 - exist\n====>" << DEFAULT << std::endl;
        std::cin >> input;
        if (input == "1")
            std::cout << "Queue is empty? " << isEmpty(queue) << std::endl;
        else if (input == "2") {
            std::cout << "Enter a symbol: ";
            std::cin >> input;
            if (input.length() > 1){
                std::cout << RED << "Incorrect input:(" << DEFAULT << std::endl;
                continue;
            }
            push(queue, input[0]);
        }
        else if (input == "3")
            pop(queue);
        else if (input == "4")
            printQueuesData(queue);
        else if (input == "5")
            getSize(queue);
        else if (input == "6") {
            clear(queue);
            std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
            exit(0);
        }
        else {
            std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
        }
    }
}
