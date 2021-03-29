//
// Created by Wynn Elease on 3/29/21.
//

#ifndef LAB7_STACK_H
#define LAB7_STACK_H
#include <stdlib.h>
#include <iostream>
#include <random>
#include "Tree.h"

# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

typedef struct s_node {
	int 	l;
	TreeNode *node;
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
void 		push(t_stack *stack, TreeNode *node, int l);
void        pop(t_stack *stack);
void        clear(t_stack *stack);
void        printAllStackData(t_stack *stack);
#endif //LAB7_STACK_H
