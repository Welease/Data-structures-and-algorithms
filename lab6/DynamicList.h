//
// Created by tanzilya on 01.03.2021.
//

#ifndef LAB6_DYNAMICLIST_H
#define LAB6_DYNAMICLIST_H

#include <iostream>
#include <cstring>

# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

typedef struct s_node {
    char *          data;
    struct s_node * next;
}				t_node;

typedef struct s_list {
    t_node *    head;
    int 	    size;
}			t_list;

void            init(t_list *&list);
bool            isEmpty(t_list *list);

int				size(t_list *list);
t_node			*last(t_list *temp);
t_node			*newNode(const char *data);

void			pushBefore(t_list *list, const char *elem, t_node *new_node);
void			pushAfter(t_list *list, const char *elem, t_node *new_node);
void			pushFront(t_list *list, t_node *new_node);
void			pushBack(t_list *list, t_node *new_node);
void			clear(t_list *&list);
void            printListsData(t_list *list);

void            popElement(t_list	*list, const char *elem);
void            popBack(t_list *list);
void            popFront(t_list	*list);
int				getIndex(t_list *list, const char *elem);
void			popBackToStack(t_list *list, t_list *stack);
void			popFrontToStackList(t_list *list, t_list *stack);
void			popElemToStackList(t_list *list, t_list *stack, char *data);

#endif //LAB6_DYNAMICLIST_H
