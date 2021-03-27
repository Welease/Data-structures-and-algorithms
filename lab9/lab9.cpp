//
// Created by Wynn Elease on 3/27/21.
//
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include "Tree.h"

void formTree(int n, TreeNode **parent, std::ifstream & file) {
	TreeNode *now;
	int x, nl, nr;

	now = *parent;
	if (n == 0)
		*parent = nullptr;
	else {
		nl = n / 2;
		nr = n - nl - 1;
		file >> x;
		now = new TreeNode;
		now->key = x;
		formTree(nl, &now->left, file);
		formTree(nr, &now->right, file);
		*parent = now;
	}
}

void printReversSim(TreeNode *root, int l) {
	if (root) {
		printReversSim(root->right, l + 1);
		for (int i = 1; i <= l; ++i) {
			std::cout << "    ";
		}
		std::cout << root->key << std::endl;
		printReversSim(root->left, l + 1);
	}
}

void printInStraight(TreeNode *root, int l) {
	if (root) {
		for (int i = 1; i <= l; ++i) {
			std::cout << "    ";
		}
		std::cout << root->key << std::endl;
		printInStraight(root->left, l + 1);
		printInStraight(root->right, l + 1);
	}
}


void printInSim(TreeNode *root, int l) {
	if (root) {
		printInSim(root->left, l + 1);
		for (int i = 1; i <= l; ++i) {
			std::cout << "    ";
		}
		std::cout << root->key << std::endl;
		printInSim(root->right, l + 1);
	}
}

int main() {
	std::ifstream file("/Users/welease/Data-structures-and-algorithms/lab9/input.txt");
	TreeNode *root = nullptr;
	int arr[21] = {8, 9, 11, 15, 19, 20, 21, 7, 3, 2, 1, 5, 6, 4, 13, 14, 10, 12, 17, 16, 18};
	formTree(7, &root, file);
	printInStraight(root, 0);
	std::cout << "------------------" << std::endl;
	printInSim(root, 0);
	std::cout << "------------------" << std::endl;
	printReversSim(root, 0);
}