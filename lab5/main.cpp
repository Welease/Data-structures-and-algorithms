#include <iostream>
#include "ListOnArray.h"

int main() {
    std::string input;
    std::string tmp;
    t_list *list;
    init(list);
    while (1) {
        std::cout << BLUE << "Choose option:\n" <<
                  "1 - push element back\n" <<
                  "2 - push element front\n" <<
                  "3 - push element before...\n" <<
                  "4 - push element after...\n" <<
                  "5 - pop element back\n" <<
                  "6 - pop element front\n" <<
                  "7 - pop element\n" <<
                  "8 - print all list's data\n" <<
                  "9 - get index of element\n" <<
                  "10 - exist\n====>" << DEFAULT << std::endl;
        std::cin >> input;
        if (input == "1") {
            std::cout << "Input data: ";
            std::cin >> input;
            pushBack(list, input);
        }
        else if (input == "2") {
            std::cout << "Input data: ";
            std::cin >> input;
            pushFront(list, input);
        }
        else if (input == "3") {
            std::cout << "Input data: ";
            std::cin >> input;
            std::cout << "Input element: ";
            std::cin >> tmp;
            pushBefore(list, tmp, input);
        }
        else if (input == "4") {
            std::cout << "Input data: ";
            std::cin >> input;
            std::cout << "Input element: ";
            std::cin >> tmp;
            pushAfter(list, tmp, input);
        }
        else if (input == "5")
            popBack(list);
        else if (input == "6")
            popFront(list);
        else if (input == "7") {
            std::cout << "Input element: ";
            std::cin >> input;
            popElement(list, input);
        }
        else if (input == "8")
            printListsData(list);
        else if (input == "9") {
            std::cout << "Input element: ";
            std::cin >> tmp;
            std::cout << "Index: " << findElement(list, tmp) << std::endl;
        }
        else if (input == "10") {
            clear(list);
            std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
            exit(0);
        }
        else {
            std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
        }
    }
}