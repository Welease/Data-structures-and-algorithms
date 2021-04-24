//
// Created by tanzilya on 24.04.2021.
//

#ifndef LAB7_TREENODE_H
#define LAB7_TREENODE_H

# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

#include <iostream>
#include <cstdlib>

struct TreeNode {
    int key;
    int counter;
    TreeNode *left;
    TreeNode *right;
};

#endif //LAB7_TREENODE_H
