//
// Created by Wynn Elease on 2/27/21.
//

#ifndef LAB2_QUEUE_H
#define LAB2_QUEUE_H
#define SIZE 6

# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

#include <iostream>

typedef struct	s_queue {
	int queue[SIZE];
	int begin;
	int end;
}				t_queue;

t_queue		*getQueue();
void		clear(t_queue *queue);
int 		getSize(t_queue *queue);
bool 		isEmpty(t_queue *queue);
bool		isFull(t_queue *queue);
void		push(t_queue *queue, int data);
int			pop(t_queue *queue);
int			begin(t_queue *queue);
void		printQueuesData(t_queue *queue);

#endif //LAB2_QUEUE_H
