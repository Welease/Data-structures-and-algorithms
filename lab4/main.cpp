#include <iostream>
#include "StaticList.h"

int main() {
    std::string input;
    std::string tmp;
    struct staticList<int> *list;
    init(&list);
    while (1) {
        std::cout << BLUE << "Choose option:\n" <<
                  "1 - push element back\n" <<
                  "2 - push element front\n" <<
                  "3 - push element before...\n" <<
                  "4 - push element after...\n" <<
                  "5 - pop element back\n" <<
                  "6 - pop element front\n" <<
                  "7 - pop element\n" <<
                  "8 - pop element before\n" <<
                  "9 - pop element after\n" <<
                  "10 - print all list's data\n" <<
                  "11 - check empty list or not\n" <<
                  "12 - check full list or not\n" <<
                  "13 - get index of element\n" <<
                  "14 - push element with sort\n" <<
                  "15 - exist\n====>" << DEFAULT << std::endl;
        std::cin >> input;
        if (input == "1") {
            std::cout << "Input data: ";
            std::cin >> input;
            pushBack(list, std::stoi(input));
        }
        else if (input == "2") {
            std::cout << "Input data: ";
            std::cin >> input;
            pushFront(list, std::stoi(input));
        }
        else if (input == "3") {
            std::cout << "Input data: ";
            std::cin >> input;
            std::cout << "Input element: ";
            std::cin >> tmp;
            pushBefore(list, std::stoi(tmp), std::stoi(input));
        }
        else if (input == "4") {
            std::cout << "Input data: ";
            std::cin >> input;
            std::cout << "Input element: ";
            std::cin >> tmp;
            pushAfter(list, std::stoi(tmp), std::stoi(input));
        }
        else if (input == "5")
            popBack(list);
        else if (input == "6")
            popFront(list);
        else if (input == "7") {
            std::cout << "Input element: ";
            std::cin >> input;
            popElement(list, std::stoi(input));
        }
        else if (input == "8") {
            std::cout << "Input element: ";
            std::cin >> tmp;
            popBefore(list, std::stoi(tmp));
        }
        else if (input == "9") {
            std::cout << "Input element: ";
            std::cin >> tmp;
            popAfter(list, std::stoi(tmp));
        }
        else if (input == "10")
            printListsData(list);
        else if (input == "11")
            std::cout << "List is empty? " << isEmpty(list) << std::endl;
        else if (input == "12")
            std::cout << "List is full? " << isFull(list) << std::endl;
        else if (input == "13") {
            std::cout << "Input element: ";
            std::cin >> tmp;
            findElement(list, std::stoi(tmp));
        }
        else if (input == "14") {
            std::cout << "Input element: ";
            std::cin >> input;
            pushSort(list, std::stoi(input));
        }
        else if (input == "15") {
            clear(list);
            std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
            exit(0);
        }
        else {
            std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
        }
    }
}
