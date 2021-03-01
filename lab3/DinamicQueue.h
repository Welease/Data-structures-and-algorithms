//
// Created by tanzilya on 01.03.2021.
//

#ifndef LAB3_DINAMICQUEUE_H
#define LAB3_DINAMICQUEUE_H

# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

#include <iostream>

typedef struct s_node {
    char data;
    struct s_node *next;
    struct s_node *prev;
}               t_node;

typedef struct	s_queue {
    t_node *_abstractNode;
    int count;
}				t_queue;

t_queue		*getQueue();
void		clear(t_queue *queue);
int 		getSize(t_queue *queue);
bool 		isEmpty(t_queue *queue);
void		push(t_queue *queue, char data);
char		pop(t_queue *queue);
char		begin(t_queue *queue);
void		printQueuesData(t_queue *queue);
void        randomWorking(t_queue *queue);
int         getRandomNumber(int min, int max);
void        delRandom(t_queue *queue);
void        addRandom(t_queue *queue);

#endif //LAB3_DINAMICQUEUE_H
