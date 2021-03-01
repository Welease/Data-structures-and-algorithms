//
// Created by tanzilya on 01.03.2021.
//

#ifndef LAB5_LISTONARRAY_H
#define LAB5_LISTONARRAY_H
#include <iostream>
#include <cstring>
# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

#define SIZE 10

typedef struct s_node {
    std::string data;
    int next;
}               t_node;

typedef struct s_list {
    t_node  list[SIZE + 1];
    int     size;
}               t_list;

void	init(t_list *&list);
void	clear(t_list *&list);
bool    isEmpty(t_list *list);

void	pushSort(t_list *list, std::string data);

void	pushBack(t_list *list, std::string data);
void	pushFront(t_list *list, std::string data);
void	pushBefore(t_list *list, std::string elem, std::string data);
void	pushAfter(t_list *list, std::string elem, std::string data);

void	popElement(t_list *list, std::string elem);
void	popFront(t_list *list);
void	popBack(t_list *list);

void	printListsData(t_list *list);

int     findElement(t_list *list, std::string elem);

#endif
