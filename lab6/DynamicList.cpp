//
// Created by tanzilya on 01.03.2021.
//

#include "DynamicList.h"

void init(t_list *&list) {
    list = new t_list;
    list->head = new t_node;
    list->head->data = nullptr;
    list->head->next = nullptr;
    list->size = 0;
}

bool isEmpty(t_list *list) { return !list || !list->head || list->head->next; }

int	 size(t_list *list) {
    if (!list || !list->head)
        return -1;
    return (list->size);
}

void	clear(t_list *&list) {
    if (!(list) || !(list)->head)
        return;
    t_node *temp = (list)->head;
    t_node *next;
    while (temp) {
        next = temp->next;
        if (temp->data)
            free(temp->data);
        delete temp;
        temp = next;
    }
    list->size = 0;
    delete list;
    list = nullptr;
}

t_node *newNode(const char *data) {
    t_node *newElem = new t_node;
    newElem->data = strdup(data);
    newElem->next = nullptr;
    return (newElem);
}

t_node		*last(t_list *list) {
    t_node *temp = list->head->next;
    if(!temp)
        return (nullptr);
    while (temp->next)
        temp = temp->next;
    return (temp);
}

void		pushFront(t_list *list, t_node *new_node) {
    t_node *new_head;

    if (new_node) {
        new_head = new_node;
        if(!(list->head))
            list->head->next = new_head;
        else {
            new_head->next = list->head->next;
            list->head->next = new_head;
        }
        list->size++;
    }
}

void pushBack(t_list *list, t_node *new_node) {
    if (list && list->head && new_node) {
        if(list->head->next)
            last(list)->next = new_node;
        else
            list->head->next = new_node;
        list->size++;
    }
}

t_node *findBefore(t_list *list, const char *elem) {
    t_node * temp = list->head;
    while (temp->next) {
        if (strcmp(temp->next->data, elem) == 0)
            return temp;
        temp=temp->next;
    }
    return (nullptr);
}

t_node *findAfter(t_list *list, const char *elem) {
    t_node * temp = list->head->next;
    while (temp) {
        if (strcmp(temp->data, elem) == 0)
            return temp;
        temp = temp->next;
    }
    return (nullptr);
}

void	pushBefore(t_list *list, const char *elem, t_node *new_node) {
    if (list && list->head && new_node) {
        {
            t_node *temp;
            if (!(temp = findBefore(list, elem))) {
                free(new_node->data);
                delete new_node;
                return;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
        list->size++;
    }
}

void	pushAfter(t_list *list, const char *elem, t_node *new_node) {
    if (list && list->head && new_node) {
        if (list->head->next == nullptr)
            list->head->next = new_node;
        else {
            t_node *temp;
            if (!(temp = findAfter(list, elem))) {
                free(new_node->data);
                delete new_node;
                return;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
        list->size++;
    }
}

t_node *getBeforeLast(t_node *temp) {
    if(!temp->next || !temp->next->next)
        return nullptr;
    while (temp->next->next)
        temp = temp->next;
    return temp;
}

void     popElement(t_list	*list, const char *elem) {
    if (list && list->head) {
        t_node *temp;
        if (!(temp = findBefore(list, elem)))
            return;
        else {
            t_node *deleted = temp->next;
            temp->next = deleted->next;
            free(deleted->data);
            deleted->data = nullptr;
            delete deleted;
            deleted = nullptr;
        }
        list->size--;
    }
}

void      popBack(t_list *list) {
    if (!list || !list->head || !list->head->next)
        return;
    t_node *temp = getBeforeLast(list->head);
    if(temp == nullptr) {
        free(list->head->next->data);
        list->head->next->data = nullptr;
        delete list->head->next;
        list->head->next = nullptr;
    }
    else {
        free(temp->next->data);
        delete temp->next;
        temp->next = nullptr;
    }
    list->size--;
}

void     popFront(t_list *list) {
    if (!list || !list->head || !list->head->next)
        return;
    t_node *tmp = list->head->next;
    list->head->next = list->head->next->next;
    free(tmp->data);
    tmp->data = nullptr;
    delete tmp;
    tmp = nullptr;
}

void     printListsData(t_list *list) {
    if (!list || !list->head || !list->head->next) {
        std::cout << RED << "List is empty :(" << DEFAULT << std::endl;
        return;
    }
    std::cout << GREEN << "Printing List's data..." << std::endl;
    std::cout << "List size = " << list->size << DEFAULT "\n";
    t_node *temp_node = list->head->next;
    while (temp_node) {
        std::cout << temp_node->data << "  ";
        temp_node = temp_node->next;
    }
    std::cout << "\n";
}

int		findElement(t_list *list, const char *elem)
{
    if (!list || !list->head || !list->head->next)
        return -1;
    t_node *temp = list->head->next;
    int i = 0;
    while (temp) {
        if (strcmp(temp->data, elem) == 0)
            return i;
        temp = temp->next;
        i++;
    }
    return (-1);
}


void		popBackToStack(t_list *list, t_list *stack) {
    if (!list || !stack || !list->head || !stack->head)
        return;
    t_node *moving_elem = list->head->next;
    t_node *before_moving = list->head;
    if (!moving_elem)
        return;
    while (moving_elem->next) {
        before_moving = moving_elem;
        moving_elem = moving_elem->next;
    }
    before_moving->next = nullptr;

    if (!stack->head->next)
        stack->head->next = moving_elem;
    else {
        t_node *temp = stack->head->next;
        stack->head->next = moving_elem;
        moving_elem->next = temp;
    }
    stack->size++;
    list->size--;
}

void			popFrontToStackList(t_list *list, t_list *stack) {
    if (!list || !stack || !list->head || !stack->head)
        return;
    t_node *moving_elem = list->head->next;
    t_node *after_moving = moving_elem->next;
    moving_elem->next = nullptr;
    if (!moving_elem)
        return;
    list->head->next = after_moving;
    if (!stack->head->next)
        stack->head->next = moving_elem;
    else {
        t_node *temp = stack->head->next;
        stack->head->next = moving_elem;
        moving_elem->next = temp;
    }
    stack->size++;
    list->size--;
}



void			popElemToStackList(t_list *list, t_list *stack, char *data) {
    if (!list || !stack || !list->head || !stack->head)
        return;
    t_node *moving_elem = list->head->next;
    t_node *before_moving = list->head;
    if (!moving_elem)
        return;
    while (moving_elem->next) {
        if (strcmp(moving_elem->data, data) == 0)
            break;
        before_moving = moving_elem;
        moving_elem = moving_elem->next;
    }
    before_moving->next = moving_elem->next;
    moving_elem->next = nullptr;
    if (!stack->head->next)
        stack->head->next = moving_elem;
    else {
        t_node *temp = stack->head->next;
        stack->head->next = moving_elem;
        moving_elem->next = temp;
    }
    stack->size++;
    list->size--;
}