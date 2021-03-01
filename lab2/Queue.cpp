//
// Created by Wynn Elease on 2/27/21.
//

#include "Queue.h"

t_queue *getQueue(){
	auto * queue = new t_queue;
	queue->begin = -1;
	queue->end = -1;
	queue->count = 0;
	return queue;
}

bool isEmpty(t_queue *queue) { return queue->begin == -1; }

bool isFull(t_queue *queue) { return ((queue->begin == queue->end + 1) || (queue->begin == 0 && queue->end == SIZE - 1));}
//замыкается если конец перед началом

void push(t_queue *queue, int data) {
	if (isFull(queue)) {
		std::cout << RED << "Queue is full :(" << DEFAULT << std::endl;
		return;
	}
	if (isEmpty(queue)) {
		queue->begin = 0;
		queue->end = 0;
		queue->queue[queue->end] = data;
	}
	else {
		queue->end = (queue->end + 1) % SIZE;
		queue->queue[queue->end] = data;
	}
	queue->count++;
    std::cout << GREEN << "Element successfully pushed!" << DEFAULT << std::endl;
}

int pop(t_queue *queue) {
	int temp;

	if (isEmpty(queue)) {
		std::cout << RED << "Queue is empty!" << DEFAULT << std::endl;
		return 0;
	}
	else {
		temp = queue->begin;
		if (queue->begin == queue->end) {
			queue->begin = -1;
			queue->end = -1;
		}
		else
			queue->begin = (queue->begin + 1) % SIZE;
		queue->count--;
	}
    std::cout << GREEN << "Element successfully deleted!" << DEFAULT << std::endl;
	return temp;
}

void printQueuesData(t_queue *queue) {
	int i;

	if(isEmpty(queue)) {
		std::cout << RED << "Queue is empty!" << DEFAULT << std::endl;
		return;
	}
	std::cout << GREEN << "Queue's data:" <<  DEFAULT << std::endl;
	for (i = queue->begin; i != queue->end; i = (i + 1) % SIZE)
		std::cout << queue->queue[i] << ' ';

	std::cout << queue->queue[i] << std::endl;
}

void clear(t_queue *queue) {
	delete queue;
}

int getSize(t_queue *queue) {
    return queue->count;
}