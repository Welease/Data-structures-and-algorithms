//
// Created by tanzilya on 24.04.2021.
//

#ifndef LAB7_LISTOFLISTS_H
#define LAB7_LISTOFLISTS_H

#include <iostream>
#include <cstdlib>

# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

struct childList {
    std::string value;
    childList *next;
};

struct parentList {
    parentList *nextMain;
    childList *headChildList;
};

void initList();
bool isParentListEmpty();
bool isChildListEmpty();
void printList();
void pushToParentList();
void pushBeforeToChild(std::string & ch, parentList *tmpPar);
void pushAfterToChild(parentList *tmpPar);
void pushToChild();
void popFromParent();
void popFromChildList();
void find();
void clearAll();

#endif //LAB7_LISTOFLISTS_H
