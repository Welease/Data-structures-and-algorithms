//
// Created by tanzilya on 01.03.2021.
//

#include "ListOnArray.h"

void init(t_list *&list) {
    list = new t_list;
    list->list[0].data = "head_node";
    list->list[0].next = 0;
    list->size = 1;
    for (int i = 1; i < SIZE; i++)
    {
        list->list[i].next = -1;
    }
}

bool isEmpty(t_list *list) { return !list || list->size == 1; }

bool isFull(t_list *list) { return list && list->size == SIZE + 1; }

void clear(t_list *&list) {
    for (int i = 0; i < list->size; ++i)
        list->list[i].next = -1;
    delete list;
    list = nullptr;
}

static int findEmptyIndex(t_list *list) {
    int temp = list->list[0].next;
    int prev = 0;
    //найти ячейку (последняя) которая ссылается на -1
    while (temp != -1) {
        prev = temp;
        temp = list->list[temp].next;
    }
    return (prev);
}

static int findEmptyNode(t_list *list, int index) {
    int i = 1;
    //найти пустую ячейку
    while (i < SIZE) {
        if(list->list[i].next == -1 && i != index)
            return i;
        i++;
    }
    return (i);
}

void pushBack(t_list *list, std::string string) {
    if(isFull(list)) {
        std::cout << RED << "List is full!" << DEFAULT << std::endl;
        return;
    }
    if(list->size == 1) {
        list->list[0].next = 1;
        list->list[1].data = string;
    }
    else {
        int last_node = findEmptyIndex(list);
        int empty_node_index = findEmptyNode(list, last_node);
        list->list[last_node].next = empty_node_index;
        list->list[empty_node_index].data = string;
        list->list[empty_node_index].next = -1;
    }
    list->size++;
}

void pushFront(t_list *list, std::string string) {
    if(isFull(list)) {
        std::cout << RED << "List is full!" << DEFAULT << std::endl;
        return;
    }
    if(list->size == 1) {
        list->list[0].next = 1;
        list->list[1].data = string;
    }
    else {
        int old_head = list->list[0].next;
        int empty_node = findEmptyNode(list, findEmptyIndex(list));
        list->list[empty_node].data = string;
        list->list[empty_node].next = old_head;
        list->list[0].next = empty_node;
    }
    list->size++;
}

void	pushBefore(t_list *list, std::string elem, std::string data) {
    if(isFull(list)) {
        std::cout << RED << "List is full!" << DEFAULT << std::endl;
        return;
    }
    if (isEmpty(list)) {
        std::cout << RED << "Element not found!" << DEFAULT << std::endl;
        return;
    }
    int i = 1;
    int temp = list->list[0].next;
    int before_new;
    while(temp != -1) {
        if(list->list[temp].data == elem)
            break;
        i++;
        before_new = temp;
        temp = list->list[temp].next;
    }
    if (i == list->size) {
        std::cout << RED << "Element not in list!" << DEFAULT << std::endl;
        return;
    }
    if(i == 1) {
        pushFront(list, data);
        return;
    }
    int new_node = findEmptyNode(list, findEmptyIndex(list));
    list->list[new_node].data = data;
    list->list[new_node].next = temp;
    list->list[before_new].next = new_node;
    list->size++;
}

void	pushAfter(t_list *list, std::string elem, std::string data) {
    if(isFull(list)) {
        std::cout << RED << "List is full!" << DEFAULT << std::endl;
        return;
    }
    if (isEmpty(list)) {
        std::cout << RED << "Element not found!" << DEFAULT << std::endl;
        return;
    }
    int i = 1;
    int temp = list->list[0].next;
    while(temp != -1) {
        if(list->list[temp].data == elem)
            break;
        temp = list->list[temp].next;
        i++;
    }
    if (i == list->size) {
        std::cout << RED << "Element not in list!" << DEFAULT << std::endl;
        return;
    }
    int new_node = findEmptyNode(list, findEmptyIndex(list));
    list->list[new_node].data = data;
    list->list[new_node].next = list->list[temp].next;
    list->list[temp].next = new_node;
    list->size++;
}

void popElement(t_list *list, std::string elem) {
    if (isEmpty(list)) {
        std::cout << RED << "List is empty!" << DEFAULT << std::endl;
        return;
    }
    int i = 1;
    int before_deleted;
    int temp = list->list[0].next;
    while (temp != -1) {
        if (list->list[temp].data == elem)
            break;
        before_deleted = temp;
        temp = list->list[temp].next;
        i++;
    }
    if (i == list->size) {
        std::cout << RED << "Element not in list!" << DEFAULT << std::endl;
        return;
    }
    if (i == 1) {
        popFront(list);
        return;
    }
    list->list[before_deleted].next = list->list[temp].next;
    list->list[temp].next = -1;
    list->size--;
}

void popFront(t_list *list) {
    if (isEmpty(list)) {
        std::cout << RED << "List is empty!" << DEFAULT << std::endl;
        return;
    }
    int first_node = list->list[0].next;
    int after_first_node = list->list[first_node].next;

    list->list[0].next = after_first_node;
    list->list[first_node].next = -1;
    list->size--;
}

void popBack(t_list *list) {
    if (isEmpty(list)) {
        std::cout << RED << "List is empty!" << DEFAULT << std::endl;
        return;
    }
    int i = 1;
    int temp = list->list[0].next;
    while (i < list->size - 2) {
        temp = list->list[temp].next;
        i++;
    }
    if (i == 1)
        list->list[temp].next = -1;
    else
        list->list[temp].next = -1;
    list->size--;
}

void printListsData(t_list *list) {
    std::cout << GREEN << "Printing list's info..." << std::endl;
    std::cout << "List size = " << list->size << DEFAULT << std::endl;
    if (isEmpty(list)) {
        std::cout << RED << "List is empty!" << DEFAULT << std::endl;
        return;
    }
    int temp;
    temp = list->list[0].next;
    while (temp != -1) {
        std::cout << list->list[temp].data << "  ";
        temp = list->list[temp].next;
    }
    std::cout << std::endl;
}

int     findElement(t_list *list, std::string elem) {
    int i = 1;
    int temp;
    temp = list->list[0].next;
    while (temp != -1) {
        if (list->list[temp].data == elem)
            return (i);
        temp = list->list[temp].next;
        i++;
    }
    return (-1);
}