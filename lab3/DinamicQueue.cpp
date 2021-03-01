//
// Created by tanzilya on 01.03.2021.
//

#include "DinamicQueue.h"

t_queue *getQueue() {
    auto *queue = new t_queue;
    queue->count = 0;
    queue->_abstractNode = new t_node;
    queue->_abstractNode->data = '\0';
    queue->_abstractNode->next = queue->_abstractNode;
    queue->_abstractNode->prev = queue->_abstractNode;
    return queue;
}

bool isEmpty(t_queue *queue) {
    return queue == nullptr || queue->count == 0;
}

int getSize(t_queue *queue) {
    return queue == nullptr ? 0 : queue->count;
}

char begin(t_queue *queue) {
    if (isEmpty(queue))
        return '\0';
    return queue->_abstractNode->next->data;
}

void push(t_queue *queue, char data) {
    t_node *tmp = queue->_abstractNode->next;
    auto *newNode = new t_node;
    while (tmp->next != queue->_abstractNode) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
    newNode->next = queue->_abstractNode;
    queue->_abstractNode->prev = newNode;
    newNode->data = data;
    queue->count++;
    std::cout << GREEN << "Element successfully pushed!" << DEFAULT << std::endl;
}

char pop(t_queue *queue) {
    char    data;
    t_node *tmp = queue->_abstractNode->next;
    if (isEmpty(queue)) {
        std::cout << RED << "Queue is empty!" << DEFAULT << std::endl;
        return '\0';
    }
    queue->_abstractNode->next = tmp->next;
    queue->_abstractNode->next->prev = queue->_abstractNode;
    data = tmp->data;
    delete tmp;
    queue->count--;
    std::cout << GREEN << "Element successfully deleted!" << DEFAULT << std::endl;
    return data;
}

void printQueuesData(t_queue *queue) {
    std::cout << GREEN << "Printing queue's data..." << DEFAULT << std::endl;
    if (isEmpty(queue)) {
        std::cout << RED << "Queue is empty!" << DEFAULT << std::endl;
        return;
    }
    t_node *tmp = queue->_abstractNode->next;
    while (tmp != queue->_abstractNode) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

void clear(t_queue *queue) {
    t_node *tmp = queue->_abstractNode->next;
    t_node *toDelete;
    while (tmp != queue->_abstractNode) {
        toDelete = tmp;
        tmp = tmp->next;
        delete toDelete;
    }
    delete queue->_abstractNode;
    delete queue;
    std::cout << GREEN << "Queue successfully deleted" << DEFAULT << std::endl;
}

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void addRandom(t_queue *queue) {
    char toPush;
    int count = getRandomNumber(1, 3);
    std::cout << BLUE << "Start to adding " << count << " random elements..." << DEFAULT << std::endl;
    for (int i = 0; i < count; ++i) {
        toPush = (char)getRandomNumber(65, 90);
        std::cout << GREEN << "Pushing " << toPush << " to queue..." << DEFAULT << std::endl;
        push(queue, toPush);
    }
}

void delRandom(t_queue *queue) {
    int count = getRandomNumber(1, 3);
    std::cout << BLUE << "Start to deleting " << count << " elements from queue..." << DEFAULT << std::endl;
    for (int i = 0; i < count; ++i) {
        pop(queue);
    }
}
