#include <iostream>
#include "Stack.h"

int main() {
    t_stack *stack = getNewStack();
    t_stack *additionalStack = getNewStack();
    std::string input;
    while (1) {
        std::cout << BLUE << "Choose option:\n" <<
                             "1 - get size of stack\n" <<
                             "2 - check empty stack or not\n" <<
                             "3 - get data from stack's top element\n" <<
                             "4 - push element to stack\n" <<
                             "5 - pop element from stack\n" <<
                             "6 - print all data from stack\n" <<
                             "7 - push random elements to stack\n" <<
                             "8 - print all data from additional stack\n" <<
                             "9 - exist\n====>" << DEFAULT << std::endl;
        std::cin >> input;
        if (input == "1")
            std::cout << "Size of stack is: " << getSize(stack) << std::endl;
        else if (input == "2")
            std::cout << "Stack is empty? " << isEmpty(stack) << std::endl;
        else if (input == "3") {
            try {
                int ret = getTopsData(stack);
                std::cout << "Stack's top element data: " << ret << std::endl;
            }
            catch (std::exception & ex) {}
        }
        else if (input == "4") {
            std::cout << "1 - add new element\n" <<
            "2 - push element from additional stack\n---->" << std::endl;
            std::cin >> input;
            if (input == "1") {
                std::cout << "Enter a number: ";
                std::cin >> input;
                push(stack, std::stoi(input));
            }
            else if (input == "2")
                moveElement(additionalStack, stack);
            else
                std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
        }
        else if (input == "5") {
            std::cout << "1 - delete element\n" <<
                            "2 - push element to additional stack\n---->" << std::endl;
            std::cin >> input;
            if (input == "1")
                pop(stack);
            else if (input == "2")
                moveElement(stack, additionalStack);
            else
                std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
        }
        else if (input == "6")
            printAllStackData(stack);
        else if (input == "7")
            pushRandomElements(stack);
        else if (input == "8")
            printAllStackData(additionalStack);
        else if (input == "9") {
            clear(additionalStack);
            clear(stack);
            std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
            exit(0);
        }
        else {
            std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
        }
    }
}
