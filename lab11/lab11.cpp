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
		clear(root->left);
		clear(root->right);
        delete root;
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

void find(TreeNode *root, TreeNode **parent, int key, bool & flag) {
    if (root) {
        if (root->key == key) {
            flag = true;
            *parent = root;
            return;
        }
        find(root->left,parent, key, flag);
        find(root->right, parent, key, flag);
    }
}

TreeNode *newNode(int key) {
    TreeNode *root;
    root = new TreeNode;
    root->key = key;
    root->left = nullptr;
    root->right = nullptr;
}

void insert(TreeNode **root) {
    TreeNode *found = nullptr;
    bool flag = false, place = false; //false is right
    int key, toFind;
    if (!*root) {
        std::cout << "Tree is empty, so input just key:";
        std::cin >> key;
        *root = newNode(key);
    }
    else {
        std::cout << "Input the parent element:"; std::cin >> toFind;
        find(*root, &found, toFind, flag);
        if (flag) {
            if (found->left && found->right)
                std::cout << "Can't add the element:(" << std::endl;
            else if (!found->left && !found->right) {
                std::cout << "Input the key:"; std::cin >> key;
                std::cout << "addElement to left or to right? (1 - left, 0 - right)"; std::cin >> place;
                place ? found->left = newNode(key) : found->right = newNode(key);
            }
            else if (!found->left) {
                std::cout << "Input the key:"; std::cin >> key;
                found->left = newNode(key);
            }
            else {
                std::cout << "Input the key:"; std::cin >> key;
                found->right = newNode(key);
            }
        }
        else
            std::cout << "Such element was not found:(" << std::endl;
    }
}

int main() {
	std::string input;
	TreeNode *root = nullptr;
	TreeNode *found = nullptr;
	bool flag = false;
	int n, key;
	while (1) {
		std::cout << BLUE << "Choose option:\n" <<
				  "1 - add element\n" <<
				  "2 - print in reverse symmetrical order\n" <<
				  "3 - find element\n" <<
				  "4 - clear tree\n" <<
				  "5 - exit\n====>" << DEFAULT << std::endl;
		std::cin >> input;
		if (input == "1") {
			insert(&root);
		}
		else if (input == "2") {
			std::cout << "in reverse symmetrical order" << std::endl;
			printReversSym(root, 0);
		}
		else if (input == "3") {
		    std::cout << "Input key:" << std::endl;
		    std::cin >> key;
		    find(root, &found, key, flag);
		    if (flag)
		        std::cout << found->key << std::endl;
		    else
		        std::cout << "value not found:(" << std::endl;
		    flag = false;
		}
		else if (input == "4") {
		    clear(root);
		    root = nullptr;
		}
		else if (input == "5")
			exit(0);
		else
			std::cout << RED << "Incorrect command:(" << DEFAULT << std::endl;
	}
}