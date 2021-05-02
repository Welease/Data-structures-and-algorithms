//
// Created by tanzilya on 23.04.2021.
//
#include "listOfLIsts.h"

int countOfElements;
parentList *parentHead;

void initList() {
    parentHead = new parentList();
    parentHead -> nextParent = NULL;
    parentHead -> headChildList = NULL;
    countOfElements = 0;
}

bool isParentListEmpty(){ return parentHead->nextParent == NULL; }

bool isChildListEmpty(parentList *curParent){ return  (curParent -> headChildList -> next == NULL); }

void printList() {
    std::cout << GREEN << "Printing list: " << DEFAULT << std::endl;
    if (!isParentListEmpty()) {
        parentList *tmp = parentHead -> nextParent;
        while (tmp) {
            std::cout << "In " << tmp -> headChildList -> value << ":\n";
            int i = 1;
            if (!isChildListEmpty(tmp)) {
                childList *tmpChild = tmp -> headChildList -> next;
                while (tmpChild) {
                    std::cout << "   " << i << ") " << tmpChild -> value << "\n";
                    tmpChild = tmpChild -> next;
                    i++;
                }
            }
            else std::cout << "   " <<RED << "listNode is empty:(" << DEFAULT << std::endl;
            tmp = tmp -> nextParent;
        }
    }
    else std::cout << RED << "listNode is empty:(" << DEFAULT << std::endl;
}

int pushToParentBefore(std::string & input, int & i, parentList *&tmp, parentList *& cur, std::string & ch) {
    if (!isParentListEmpty()){
        parentList *Pred = parentHead;
        while (i == -1){
            cur = parentHead-> nextParent;
            std::cout << "Input list before which you want insert list: ";std::cin >> input;
            while (cur) {
                if (cur ->headChildList-> value == input) break;
                cur = cur -> nextParent;
                Pred = Pred -> nextParent;
            }
            if (cur) i++;
            else { std::cout <<RED << "Can't find such list :(" << DEFAULT << std::endl; }
        }
        tmp -> nextParent = cur;
        tmp ->headChildList-> next = NULL;
        Pred -> nextParent = tmp;
        return 1;
    }
    else std::cout << RED << "listNode is empty:(" << DEFAULT << std::endl; ch = "";
    return 0;
}

int pushToParentAfter(int & i,  parentList *&tmp, parentList *& cur, std::string & input) {
    if (!isParentListEmpty()){
        while (i == -1) {
            cur = parentHead->nextParent;
            std::cout << "Input list after which you want insert list: "; std::cin >> input;
            while ((cur) && (cur -> headChildList-> value != input))
                cur = cur -> nextParent;
            if (cur) i++;
            else { std::cout <<RED << "Can't find such list :(" << DEFAULT << std::endl; }
        }
        tmp -> nextParent = cur -> nextParent;
        tmp ->headChildList-> next = NULL;
        cur -> nextParent = tmp;
        return 1;
    }
    else {
        tmp -> nextParent = NULL;
        tmp ->headChildList-> next = NULL;
        parentHead -> nextParent = tmp;
        return 1;
    }
}

void pushToParentList() {
    std::string input;
    parentList *cur = nullptr;
    parentList *tmp = new parentList;
    tmp->headChildList = new childList;
    std::string ch = "";
    while (ch != "0" && ch != "1"){
        std::cout << "Push:\n 0 - before input list\n 1 - after input list\n====>";
        std::cin >> ch;
        int i = -1;
        if (ch == "0" && pushToParentBefore(input, i, tmp, cur, ch))
            break;
        else if (ch == "1" && pushToParentAfter(i, tmp, cur, input))
            break;
        else std::cout << RED << "Incorrect input" << DEFAULT << std::endl; ch = "";
    }
    std::cout << "Input name of new list: "; std::cin >> input;
    tmp ->headChildList-> value = input; countOfElements++;
    std::cout << GREEN << "listNode successfully added to list of list" << DEFAULT << std::endl;
}

void pushBeforeToChild(std::string & ch, parentList *tmpPar) {
    std::string input;
    childList *head = tmpPar -> headChildList, *chTmp;
    childList *tmp = new childList;
    int i;
    if (!isChildListEmpty(tmpPar)) {
        childList *Pred = head;
        i = -1;
        while (i == -1){
            chTmp = head -> next;
            std::cout << "Input element before which you want insert list: ";std::cin >> input;
            while (chTmp) {
                if (chTmp -> value == input) break;
                chTmp = chTmp -> next;
                Pred = Pred -> next;
            }
            if (chTmp) i++;
            else std::cout << RED << "Can't find such string:(" << DEFAULT << std::endl;
        }
        tmp -> next = chTmp;
        Pred -> next = tmp;
        std::cout << "Input string: "; std::cin >> input;
        std::cout << GREEN << "value successfully added!" << DEFAULT << std::endl; tmp -> value = input;
    }
    else std::cout << RED << "listNode is empty:(" << DEFAULT << std::endl;
}

void pushAfterToChild(parentList *tmpPar) {
    int i; std::string input;
    childList *head = tmpPar -> headChildList;
    childList *chTmp, *tmp = new childList;
    if (!isChildListEmpty(tmpPar)) {
        i = -1;
        while (i == -1) {
            chTmp = head -> next;
            std::cout << "Input list after which you want insert list: ";std::cin >> input;
            while ((chTmp) && (chTmp -> value != input))
                chTmp = chTmp -> next;
            if (chTmp) i++;
            else std::cout << RED << "Can't find such string:(" << DEFAULT << std::endl;
        }
        tmp -> next = chTmp -> next;
        chTmp -> next = tmp;
    }
    else {
        tmp -> next = NULL;
        head -> next = tmp;
    }
    std::cout << "Input string: "; std::cin >> input;
    std::cout << GREEN << "value successfully added!" << DEFAULT << std::endl; tmp -> value = input;
}

void pushToChild(){
    if (!isParentListEmpty()){
        std::string input;
        parentList *tmpPar = nullptr;
        int i = -1;
        while (i == -1) {
            tmpPar = parentHead -> nextParent;
            std::cout << "Input name of list where you want to insert element: ";
            std::cin >> input;
            while ((tmpPar) && (tmpPar -> headChildList -> value != input))
                tmpPar = tmpPar -> nextParent;
            if (tmpPar) i++;
            else { std::cout << RED << "Can't find such list:(" << DEFAULT << std::endl; }
        }
        std::string ch = "";
        while ((ch != "0") && (ch != "1")){
            std::cout << "Push:\n 0 - before \n 1 - after \n ====>"; std::cin >> ch;
            if (ch == "0") {pushBeforeToChild(ch, tmpPar); break; }
            else if (ch == "1") {pushAfterToChild(tmpPar); break;}
            else std::cout << RED << "Incorrect input:(" << DEFAULT << std::endl; ch = "";
        }
    }
    else std::cout << RED << "listNode of list is empty:(" << DEFAULT << std::endl;
}


void popFromParent(){
    if (!isParentListEmpty()){
        std::string input;
        parentList *curParent, *prevParent;
        childList *curChild;
        int i = -1;
        while (i == -1) {
            curParent = parentHead -> nextParent;
            prevParent = parentHead;
            std::cout << "Input name of list: \n===>"; std::cin >> input;
            while (curParent != NULL) {
                if (curParent -> headChildList -> value == input) break;
                curParent = curParent -> nextParent;
                prevParent = prevParent -> nextParent;
            }
            if (curParent) { i++; }
            else { std::cout << RED << "Can't find such element:(" << DEFAULT << std::endl; }
        }

        while (curParent -> headChildList -> next != NULL) {
            curChild = curParent -> headChildList;
            curParent -> headChildList = curParent -> headChildList -> next;
            delete curChild;
        }

        delete curParent -> headChildList;

        prevParent -> nextParent = curParent -> nextParent;
        delete curParent;
        std::cout << GREEN << "value successfully deleted!" << DEFAULT << std::endl;
    }
    else std::cout << RED << "listNode is empty:(" << DEFAULT << std::endl;
}

void popFromChildList(){
    if (!isParentListEmpty()){
        printList();
        std::string input;
        parentList *tmpParent = nullptr;
        int i = -1;
        while (i == -1) {
            tmpParent = parentHead -> nextParent;
            std::cout << "Input name of list: "; std::cin >> input;
            while (tmpParent && (tmpParent->headChildList->value != input))
                tmpParent = tmpParent -> nextParent;
            if (tmpParent) i++;
            else std::cout << RED << "Can't find such string:(" << DEFAULT << std::endl;
        }
        if (!isChildListEmpty(tmpParent)) {
            childList *head = tmpParent -> headChildList;
            childList *cur = nullptr;
            childList *prev = nullptr;
            i = -1;
            while (i == -1) {
                cur = head -> next;
                prev = head;
                std::cout << "Input string: ";std::cin >> input;
                while (cur) {
                    if (cur -> value == input) break;
                    cur = cur -> next;
                    prev = prev -> next;
                }
                if (cur != NULL) { i++; }
                else { std::cout << RED << "Can't find such string:(" << DEFAULT << std::endl; }
            }
            prev -> next = cur -> next;
            std::cout << GREEN << "value successfully deleted" << DEFAULT <<std::endl;
            delete cur;
        }
        else std::cout << RED << "listNode is empty:(" << DEFAULT << std::endl;
    }
    else std::cout << RED << "listNode of list is empty:(" << DEFAULT << std::endl;
}

void find() {
    if (!isParentListEmpty()){
        printList();
        std::string toFind;
        std::cout << "Input string:\n====>";
        std::cin >> toFind;
        int j = 0;
        parentList *tmpParent = parentHead->nextParent;
        while (tmpParent) {
            std::cout << "\n Search in: " << tmpParent->headChildList->value << "'s list... ";
            if (!isChildListEmpty(tmpParent)) {
                int i = 1;
                childList *tmpChild = tmpParent -> headChildList -> next;
                while (tmpChild && (tmpChild -> value != toFind)) {
                    tmpChild = tmpChild -> next;
                    i++;
                }
                if (tmpChild) { std::cout << "String " << toFind << " found\n"; j++;}
                else std::cout << "This list haven't such string" << std::endl;
            }
            else std::cout << RED << "listNode " << tmpParent->headChildList->value << " is empty\n" << DEFAULT;
            tmpParent = tmpParent -> nextParent;
        }
        if (j==0) std::cout << RED << "Can't find such string:(" << DEFAULT << std::endl;
    }
    else std::cout << RED << "Sorry, list is empty:(" << DEFAULT << std::endl;
}

void clearAll(){
    parentList *curParentHead;
    childList *curChildHead;
    while (parentHead) {
        curParentHead = parentHead;
        while (curParentHead -> headChildList != NULL) {
            curChildHead = curParentHead -> headChildList;
            curParentHead -> headChildList = curParentHead -> headChildList -> next;
            delete curChildHead;
        }
        parentHead = curParentHead -> nextParent;
        delete curParentHead;
    }
    std::cout << GREEN << "listNode is successfully cleared" << DEFAULT << std::endl;
}