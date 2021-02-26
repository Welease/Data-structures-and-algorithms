#include <iostream>
#include "Stack.h"

int main() {
    t_stack *stack = getNewStack();
    printAllStackData(stack);
    for (int i = 1; i < 11; ++i){
        push(stack, i);
    }
    printAllStackData(stack);
    pop(stack);
    printAllStackData(stack);
}
