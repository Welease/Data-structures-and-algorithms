//
// Created by tanzilya on 24.04.2021.
//
#include "TreeNode.h"
TreeNode *root= nullptr;

void printSym (TreeNode *pCurrent) {
    if (pCurrent) {
        printSym(pCurrent->left);
        std::cout << pCurrent->key << "(" << pCurrent -> counter + 1 << ") " ;
        printSym(pCurrent->right);
    }
}

void printReversSym(TreeNode *root, int l) {
    if (root) {
        printReversSym(root->right, l + 1);
        for (int i = 1; i <= l; ++i)
            std::cout << "     ";
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

int checkInput() {
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Incorrect input, please try again: ";
    }
    return a;
}

void findStarting(bool & flag) {
    int key;
    TreeNode *cur;
    std::cout <<"Input key: "; key = checkInput();
    find(root, &cur, key, flag);
    if (cur) std::cout << GREEN << "Found '" << key << "' (" << cur -> counter << ")\n" << DEFAULT;
    else std::cout << RED << "Can't find such element\n" << DEFAULT;
}

void printTree(int n){
    if (root) {
        if (n==1)  { printSym(root); std::cout << std::endl;}
        if (n==2) { printReversSym(root, 0); std::cout << std::endl; }
    }
    else std::cout << RED << "Tree is empty" << DEFAULT << std::endl;
}

TreeNode *insertRecursive(TreeNode *parent, int key) {
    if (!parent) {
        parent = new TreeNode;
        parent -> key = key;
        parent -> left = parent -> right = NULL;
        parent -> counter = 0;
    }
    else {
        if (key < parent -> key) parent -> left = insertRecursive(parent->left, key);
        else if (key > parent -> key) parent -> right = insertRecursive(parent->right, key);
        else parent -> counter++;
    }
    return parent;
}


void insertIter(int key) {
    if (!root) {
        root = new TreeNode;
        root -> left = root -> right = nullptr;
        root -> key = key;
        root -> counter = 0;
    }
    else {
        TreeNode *par, *cur = root;
        while (cur) {
            par = cur;
            if (key < cur -> key) cur = cur -> left;
            else if (key > cur -> key) cur = cur -> right;
            else { cur = nullptr; cur -> counter++; }
        }
        if (key < par -> key) {
            cur = new TreeNode;
            cur -> left = cur -> right = nullptr;
            cur -> counter = 0;
            cur -> key = key;
            par -> left = cur;
        }
        else if (key > par -> key) {
            cur = new TreeNode;
            cur -> left = cur -> right = nullptr;
            cur -> counter = 0;
            cur -> key = key;
            par -> right = cur;
        }
    }
}

void addingNewNode() {
    std::string input;
    int key;
    std::cout <<"Input key: "; key = checkInput();
    std::cout << "Insert:\n 1 - recursive\n 2 - iterative\n"; std::cin >> input;
    if (input == "1") root = insertRecursive(root, key);
    if (input == "2") insertIter(key);
    std::cout << GREEN << "Element successfully added!"<< DEFAULT << std::endl;
}

void clear(TreeNode *root) {
    if (root) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

TreeNode* erase(TreeNode* parent, int key) {
    if (!parent) return parent;
    if (key < parent->key) parent->left = erase(parent->left, key);
    else if (key > parent->key) parent->right = erase(parent->right, key);
    else {
        if (parent->counter > 0) parent->counter--;
        else {
            if (!parent->left and !parent->right) return nullptr;
            else if (!parent->left) {
                TreeNode *temp = parent->right;
                free(parent);
                return temp;
            } else if (!parent->right) {
                TreeNode *temp = parent->left;
                free(parent);
                return temp;
            }
            TreeNode *temp = minValueNode(parent->right);
            parent->key = temp->key;
            parent->right = erase(parent->right, temp->key);
        }
    }
    return parent;
}

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void formTree(int n) {
    for (int i = 0; i < n; ++i)
        insertIter(getRandomNumber(0, 100));
}

int main() {
    std::string input;
    bool flag = false;
    int n, key;
    srand((time(0)));
    while (true) {
        std::cout << BLUE <<"Choose option:\n" <<"1 - create new tree\n"
             <<"2 - add element\n"
             <<"3 - search element\n"
             <<"4 - print tree in reverse symmetrical\n"
             <<"5 - print all keys\n"
             <<"6 - delete listNode\n"
             <<"0 - exit\n"
             <<"====>" << DEFAULT; std::cin >> input;
        if (input == "1") {
            std::cout << "Input count of nodes:";
            std::cin >> n;
            clear(root);
            formTree(n);
        }
        else if (input == "2") addingNewNode();
        else if (input == "3") findStarting(flag);
        else if (input == "4") printTree(2);
        else if (input == "5") printTree(1);
        else if (input == "6") {
            if (root) {
                std::cout << "Input key of element to delete: ";
                key = checkInput();
                root = erase(root, key);
                std::cout << GREEN << "Element successfully deleted!" << DEFAULT << std::endl;
            } else { std::cout << RED << "Tree is empty:(" << DEFAULT << std::endl;}
        }
        else if (input == "6") break;
    }
    clear(root);
    return 0;
}