//
// Created by tanzilya on 26.02.2021.
//
#include "Stack.h"

t_stack *getNewStack() {
    t_stack *stack = new t_stack;
    stack->top = nullptr;
    stack->size = 0;
    return stack;
}

int getSize(t_stack *stack) { return stack->size; }

bool isEmpty(t_stack *stack) {
    return stack->top == nullptr;
}

int getTopsData(t_stack *stack) {
    if (isEmpty(stack)) {
        std::cout << RED << "Stack is empty" << DEFAULT << std::endl;
        throw std::exception();
    }
    return stack->top->data;
}

void push(t_stack *stack, int data) {
    t_node *newNode = new t_node;
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

void pop(t_stack *stack) {
    if (isEmpty(stack)) {
        std::cout << RED << "Could not pop element, stack is empty" << DEFAULT << std::endl;
        return;
    }
    t_node *tmp = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    delete tmp;
}

void clear(t_stack *stack) {
    if (!stack || isEmpty(stack))
        return;
    while (stack->size)
        pop(stack);
    delete stack;
}

void printAllStackData(t_stack *stack) {
    std::cout << GREEN << "Printing stack..." << DEFAULT << std::endl;
    if (isEmpty(stack)){
        std::cout << RED << "Stack is empty" << DEFAULT << std::endl;
        return;
    }
    if (!stack) {
        std::cout << RED << "stack == nullptr" << DEFAULT << std::endl;
        return;
    }
    int i = 0;
    t_node *tmp = stack->top;
    while (tmp) {
        std::cout << i++ + 1 << " element: " << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void pushRandomElements(t_stack *stack) {
    int n;
    std::cout << "Enter number of random elements: ";
    std::cin >> n;
    while (n--)
        push(stack, getRandomNumber(0, 2147483646));
}

void moveElement(t_stack *stack, t_stack *additionalStack) {
    if (!stack)
        return;
    if (!additionalStack)
        additionalStack = getNewStack();
    if (!isEmpty(stack)) {
        t_node *tmp = stack->top;
        stack->top = tmp->next;
        tmp->next = nullptr;
        stack->size--;
        if (isEmpty(additionalStack))
            additionalStack->top = tmp;
        else {
            tmp->next = additionalStack->top;
            additionalStack->top = tmp;
        }
        additionalStack->size++;
    }
}

