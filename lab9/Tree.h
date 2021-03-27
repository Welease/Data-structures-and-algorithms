//
// Created by Wynn Elease on 3/27/21.
//

#ifndef TREE_H
#define TREE_H

typedef struct s_node {
	int key;
	int count;
	struct s_node *left;
	struct s_node *right;
}				TreeNode;

#endif //TREE_H
