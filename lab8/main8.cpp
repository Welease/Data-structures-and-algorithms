//
// Created by tanzilya on 23.04.2021.
//
#include "listOfLIsts.h"

int main() {
    initList();
    std::string input;

    while (true) {
        std::cout << BLUE << "Choose option:\n" <<
        "1 - print parent list's data\n" <<
        "2 - check empty or not parent list\n" <<
        "3 - insert empty child list to parent list\n" <<
        "4 - insert element to child list\n" <<
        "5 - pop element from parent list\n" <<
        "6 - pop element from child list\n" <<
        "7 - find element with part of information\n" <<
        "8 - clear parent list\n" <<
        "9 - exit\n" << "====>" << DEFAULT << std::endl;
        std::cin >> input;
        if (input == "1") printList();
        else if (input == "2") {
            std::cout << "Parent list is ";
            if (isParentListEmpty())
                std::cout << "empty" << std::endl;
            else
                std::cout << "not empty" << std::endl;
        }
        else if (input == "3") pushToParentList();
        else if (input == "4") pushToChild();
        else if (input == "5") popFromParent();
        else if (input == "6") popFromChildList();
        else if (input == "7") find();
        else if (input == "8") { clearAll(); initList(); }
        else if (input == "9") { clearAll(); break; }
        else std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
    }
    return 0;
}