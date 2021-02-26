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

bool isEmpty(t_stack *stack) { stack->top ? true : false; }

int getTopsData(t_stack *stack) { return stack->top->data; }

void push(t_stack *stack, int data) {
    t_node *newNode = new t_node;
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

void pop(t_stack *stack) {
    if (isEmpty(stack))
        return;
    t_node *tmp = stack->top;
    stack->top = stack->top->next;
    stack->size--;
    delete tmp;
}

void clear(t_stack *stack) {
    if (!stack || isEmpty(stack))
        return;
}

void printAllStackData(t_stack *stack) {
    std::cout <<
    if (!stack) {
        std::cout << "stack == nullptr" << std::endl;

    }
    int i = 0;
    t_node *tmp = stack->top;
    while (tmp) {
        std::cout << i++ + 1 << " element: " << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

