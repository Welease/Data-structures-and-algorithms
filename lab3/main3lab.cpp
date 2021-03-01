//
// Created by tanzilya on 01.03.2021.
//

#include "DinamicQueue.h"

int main() {
    char        input;
    int         randNum;
    int         tmp;
    bool        flag = false;
    tmp = 1;
    t_queue *queue = getQueue();
    srand(time(NULL));
    std::cout << GREEN << "Random successfully inited" << DEFAULT << std::endl;
    std::cout << BLUE << "Continue? (q - quit, c - continue)" << std::endl;
    while (1) {
        if (!tmp && !flag)
            std::cout << BLUE << "Continue? (q - quit, c - continue)" << std::endl;
        input = getchar();
        if (input == '\n' && tmp != 2) {
            tmp++;
            flag = false;
            continue;
        }
        else if (input == 'q') {
            clear(queue);
            exit(0);
        }
        else if (input == 'c' || tmp == 2) {
            randNum = getRandomNumber(1, 100);
            randNum % 2 ? delRandom(queue) : addRandom(queue);
            printQueuesData(queue);
            input == 'c' ? tmp = 0 : tmp = 1;
            flag = false;
        }
        else {
            if (!flag) {
                std::cout << RED << "Incorrect input :(" << DEFAULT << std::endl;
                flag = true;
            }
            tmp = 0;
        }
    }

}
