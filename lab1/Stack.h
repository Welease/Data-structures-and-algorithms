//
// Created by tanzilya on 26.02.2021.
//

#ifndef LAB1_STACK_H
#define LAB1_STACK_H
#include <stdlib.h>
#include <iostream>
#include <random>
# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

typedef struct s_node {
    int     data;
    s_node  *next;
}               t_node;

typedef struct s_stack {
    t_node  *top;
    size_t  size;
}               t_stack;

t_stack *   getNewStack();
int         getSize(t_stack *stack);
bool        isEmpty(t_stack *stack);
int         getTopsData(t_stack *stack);
void        push(t_stack *stack, int data);
void        pop(t_stack *stack);
void        clear(t_stack *stack);
void        printAllStackData(t_stack *stack);
void        pushRandomElements(t_stack *stack);
void        moveElement(t_stack *stack, t_stack *additionalStack);

#endif //LAB1_STACK_H
