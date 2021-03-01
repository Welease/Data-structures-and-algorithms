//
// Created by tanzilya on 01.03.2021.
//

#ifndef LAB4_STATICLIST_H
#define LAB4_STATICLIST_H

#include <iostream>
#define SIZE 10

# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"
template <typename  T>
struct	staticList {
    T list[SIZE];
    int size;
};

template <typename  T>
void	init(struct	staticList<T> **list) {
    *list = new struct staticList<T>;
    (*list)->size = 0;
}

template <typename  T>
void	pushBack(struct	staticList<T> *list, T data) {
    if (isFull(list)) {
        std::cout << RED << "List is full" << DEFAULT << std::endl;
        return;
    }
    else {
        list->list[list->size] = data;
        list->size++;
    }
}

template <typename  T>
bool	isEmpty(struct	staticList<T> *list) { return !list || list->size == 0; }

template <typename  T>
bool	isFull(struct	staticList<T> *list) { return list->size == SIZE; }

template <typename  T>
int		size(struct	staticList<T> *list) { return !list ? 0 : list->size; }


template <typename  T>
void	clear(struct	staticList<T> *list) {
    delete list;
    list = nullptr;
}


template <typename  T>
void	pushFront(struct	staticList<T> *list, T data) {
    if (isFull(list)) {
        std::cout << RED << "List is full" << DEFAULT << std::endl;
        return;
    }
    if (list->size == 0) {
        list->list[list->size] = data;
        list->size++;
    }
    else {
        list->size++;
        for (int i = list->size - 1; i > 0; i--)
            list->list[i] = list->list[i - 1];
        list->list[0] = data;
    }
}

template <typename  T>
void	pushBefore(struct	staticList<T> *list, T elem, T data) {
    if (isFull(list)) {
        std::cout << RED << "List is full" << DEFAULT << std::endl;
        return;
    }
    int i = findElement(list, elem);
    if (i == -1) {
        std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
        return;
    }
    list->size++;
    for (int j = list->size - 1; j >= i; j--)
        list->list[j] = list->list[j - 1];
    list->list[i] = data;
}

template <typename  T>
void	pushAfter(struct	staticList<T> *list, T elem, T data) {
    if (isFull(list)) {
        std::cout << RED << "List is full" << DEFAULT << std::endl;
        return;
    }
    int i = findElement(list, elem);
    if (i == -1) {
        std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
        return;
    }
    i++;
    list->size++;
    for (int j = list->size - 1; j >= i; j--)
        list->list[j] = list->list[j - 1];
    list->list[i] = data;
}

template <typename  T>
void	popBack(struct	staticList<T> *list){
    if (isEmpty(list)) {
        std::cout << RED << "List is empty" << DEFAULT << std::endl;
        return;
    }
    list->size--;
}

template <typename  T>
void	popFront(struct	staticList<T> *list) {
    if (isEmpty(list)) {
        std::cout << RED << "List is empty" << DEFAULT << std::endl;
        return;
    }
    for (int j = 0; j < list->size; j++)
        list->list[j] = list->list[j + 1];
    list->size--;
}

template <typename  T>
void	popElement(struct	staticList<T> *list, T elem) {
    if (isEmpty(list)) {
        std::cout << RED << "List is empty" << DEFAULT << std::endl;
        return;
    }
    int i = findElement(list, elem);
    if (i == -1) {
        std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
        return;
    }
    if (i == 0) {
        popFront(list);
        return;
    }
    for (; i < list->size; i++)
        list->list[i] = list->list[i+1];
    list->size--;
}

template <typename  T>
void	popBefore(struct	staticList<T> *list, T elem) {
    if (isEmpty(list)) {
        std::cout << RED << "List is empty" << DEFAULT << std::endl;
        return;
    }
    int i = findElement(list, elem);
    if (i == -1) {
        std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
        return;
    }
    if (i == 0) {
        std::cout << RED << "Can't push before head :(" << DEFAULT << std::endl;
        return;
    }
    i--;
    for (; i < list->size; i++)
        list->list[i] = list->list[i+1];
    list->size--;
}

template <typename  T>
void	popAfter(struct	staticList<T> *list, T elem) {
    if (isEmpty(list)) {
        std::cout << RED << "List is empty" << DEFAULT << std::endl;
        return;
    }
    int i = findElement(list, elem);
    if (i == -1) {
        std::cout << RED << "Element not found :(" << DEFAULT << std::endl;
        return;
    }
    for (; i < list->size; i++)
        list->list[i] = list->list[i+1];
    list->size--;
}


template <typename  T>
void	printListsData(struct	staticList<T> *list) {
    std::cout << GREEN << "Printing list's data..." << DEFAULT << std::endl;
    std::cout << BLUE << "List size: " << list->size << DEFAULT << std::endl;

    for (int i = 0; i < list->size; i++)
        std::cout << list->list[i] << ' ';
    std::cout << std::endl;
}

template <typename  T>
int		findElement(struct	staticList<T> *list, T data) {
    int i = 0;
    while (i < list->size) {
        if (list->list[i] == data)
            return (i);
        i++;
    }
    return (-1);
}

template <typename  T>
void	pushSort(struct	staticList<T> *list, T data) {
    if (!list) {
        std::cout << RED << "List == nullptr" << DEFAULT << std::endl;
        return;
    }
    if (isFull(list)) {
        std::cout << RED << "List is full" << DEFAULT << std::endl;
        return;
    }
    if (list->size == 0) {
        pushFront(list, data);
        return;
    }
    int i = 0;
    while (i < list->size) {
        if (data < list->list[i]) {
            pushBefore(list, list->list[i], data);
            return;
        }
        i++;
    }
    if (i == list->size) {
        pushBack(list, data);
        return;
    }
}

#endif //LAB4_STATICLIST_H
