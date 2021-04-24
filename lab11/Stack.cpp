//
// Created by Wynn Elease on 3/29/21.
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
	return stack->top->node->key;
}

void push(t_stack *stack, TreeNode *node, int l) {
	t_node *newNode = new t_node;
	newNode->node = node;
	newNode->l = l;
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
	if (!stack->size)
		stack->top = nullptr;
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
		std::cout << i++ + 1 << " element: " << tmp->node->key << std::endl;
		tmp = tmp->next;
	}
}
