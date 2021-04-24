//
// Created by Wynn Elease on 3/27/21.
//
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include "Tree.h"
#include "Stack.h"

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void formTree(int n, TreeNode **parent) {
	TreeNode *now;
	int x, nl, nr;

	now = *parent;
	if (n == 0)
		*parent = nullptr;
	else {
		nl = n / 2;
		nr = n - nl - 1;
		x = getRandomNumber(0, 99);
		now = new TreeNode;
		now->key = x;
		formTree(nl, &now->left);
		formTree(nr, &now->right);
		*parent = now;
	}
}

void clear(TreeNode *root) {
	if (root) {
		TreeNode *right, *left;
		right = root->right;
		left = root->left;
		delete root;
		clear(left);
		clear(right);
	}
}

void printIterInSym(TreeNode *root) {
	t_stack *stack = getNewStack();
	TreeNode *t;
	int l = -1;
	while (stack->size != 0 || root != NULL) {
		if (root != NULL) {
			push(stack, root, ++l);
			root = root->left;
		} else {
			t = stack->top->node;
			l = stack->top->l;
			pop(stack);
			root = t;
			for (int i = 1; i <= l; ++i) {
				std::cout << "     ";
			}
			std::cout << root->key << std::endl;
			root = root->right;
		}
	}
}

void printReversSym(TreeNode *root, int l) {
	if (root) {
		printReversSym(root->right, l + 1);
		for (int i = 1; i <= l; ++i) {
			std::cout << "     ";
		}
		std::cout << root->key << std::endl;
		printReversSym(root->left, l + 1);
	}
}

void printInStraight(TreeNode *root, int l) {
	if (root) {
		for (int i = 1; i <= l; ++i) {
			std::cout << "     ";
		}
		std::cout << root->key << std::endl;
		printInStraight(root->left, l + 1);
		printInStraight(root->right, l + 1);
	}
}


void printInSym(TreeNode *root, int l) {
	if (root) {
		printInSym(root->left, l + 1);
		for (int i = 1; i <= l; ++i) {
			std::cout << "     ";
		}
		std::cout << root->key << std::endl;
		printInSym(root->right, l + 1);
	}
}

TreeNode *find(TreeNode *root, int key) {
    if (!root)
        return nullptr;
    if (root->key == key)
        return root;
    if (root->key >= key) {
        return find(root->left, key);
    }
    else {
        return find(root->right, key);
    }
    return nullptr;
}

int main() {
	std::string input;
	TreeNode *root = nullptr;
	int n;
	while (true) {
		std::cout << BLUE << "Choose option:\n" <<
				  "1 - create new tree\n" <<
				  "2 - print in straight order\n" <<
				  "3 - print in symmetrical order\n" <<
				  "4 - print in reverse symmetrical order\n" <<
				  "5 - print ITER in symmetrical order\n" <<
				  "6 - find element\n" <<
				  "0 - exit\n====>" << DEFAULT << std::endl;
		std::cin >> input;
		if (input == "1") {
			std::cout << "Input count of nodes:";
			std::cin >> n;
			clear(root);
			formTree(n, &root);
		}
		else if (input == "2") {
			std::cout << "in straight order:" << std::endl;
			printInStraight(root, 0);
			std::cout << std::endl;
		}
		else if (input == "3") {
			std::cout << "in straight symmetrical order:" << std::endl;
			printInSym(root, 0);
			std::cout << std::endl;
		}
		else if (input == "4") {
			std::cout << "in reverse symmetrical order" << std::endl;
			printReversSym(root, 0);
		}
		else if (input == "5") {
			std::cout << "in straight symmetrical order by ITER method:" << std::endl;
			printIterInSym(root);
		}
		else if (input == "6") {
		    std::cout << "Input the num to find:\n===>";
		    int k; std::cin >> input;
		    try { k = std::stoi(input);
		    TreeNode *tmp = find(root, k);
		    if (tmp)
		        std::cout << tmp->key << std::endl;
		    else
		        std::cout << RED << "Element not found:(" << DEFAULT << std::endl;}
		    catch (std::exception & ex) {std::cout << RED << "Incorrect argument:(" << DEFAULT << std::endl;}
		}
		else if (input == "0")
			exit(0);
		else
			std::cout << RED << "Incorrect command:(" << DEFAULT << std::endl;
	}
}