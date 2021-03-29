//
// Created by Wynn Elease on 3/27/21.
//

#ifndef TREE_H
#define TREE_H
# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"
typedef struct s_node {
	int key;
	int count;
	struct s_node *left;
	struct s_node *right;
}				TreeNode;

#endif //TREE_H
