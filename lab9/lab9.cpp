//
// Created by Wynn Elease on 3/27/21.
//
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include "Tree.h"

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void formTree(int n, TreeNode **parent, std::ifstream & file) {
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
		formTree(nl, &now->left, file);
		formTree(nr, &now->right, file);
		*parent = now;
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

int main() {
	std::ifstream file("/Users/welease/Data-structures-and-algorithms/lab9/input.txt");
	TreeNode *root = nullptr;
	int n;
	std::cout << "Input count of nodes:";
	std::cin >> n;
	formTree(n, &root, file);
	std::cout << "in straight order:" << std::endl;
	printInStraight(root, 0);
	std::cout << std::endl;
	std::cout << "in straight symmetrical order:" << std::endl;
	printInSym(root, 0);
	std::cout << std::endl;

	std::cout << "in reverse symmetrical order" << std::endl;
	printReversSym(root, 0);
}