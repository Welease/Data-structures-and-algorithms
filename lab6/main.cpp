#include <iostream>
#include "DynamicList.h"

int main() {
    t_list *list;
    t_list *stackList;
    init(list);
    init(stackList);
    std::string input;
    std::string tmp;
    while (1) {
        std::cout << BLUE << "Choose option:\n" <<
                  "1 - push element back\n" <<
                  "2 - push element front\n" <<
                  "3 - push element before...\n" <<
                  "4 - push element after...\n" <<
                  "5 - pop element back to stack list\n" <<
                  "6 - pop element front to stack list\n" <<
                  "7 - pop element to stack list\n" <<
                  "8 - print all list's data\n" <<
                  "9 - print stack list's data\n" <<
                  "10 - exist\n====>" << DEFAULT << std::endl;
        std::cin >> input;
        if (input == "1") {
            std::cout << "Input data: ";
            std::cin >> input;
            pushBack(list, newNode(input.c_str()));
        }
        else if (input == "2") {
            std::cout << "Input data: ";
            std::cin >> input;
            pushFront(list, newNode(input.c_str()));
        }
        else if (input == "3") {
            std::cout << "Input data: ";
            std::cin >> input;
            std::cout << "Input element: ";
            std::cin >> tmp;
            pushBefore(list, tmp.c_str(), newNode(input.c_str()));
        }
        else if (input == "4") {
            std::cout << "Input data: ";
            std::cin >> input;
            std::cout << "Input element: ";
            std::cin >> tmp;
            pushAfter(list, tmp.c_str(), newNode(input.c_str()));
        }
        else if (input == "5")
            popBackToStack(list, stackList);
        else if (input == "6")
            popFrontToStackList(list, stackList);
        else if (input == "7") {
            std::cout << "Input element: ";
            std::cin >> input;
            popElemToStackList(list, stackList, (char *)input.c_str());
        }
        else if (input == "8")
            printListsData(list);
        else if (input == "9") {
            printListsData(stackList);
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