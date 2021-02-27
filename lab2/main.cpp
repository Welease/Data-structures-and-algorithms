#include <iostream>
#include "Queue.h"

int main() {
	t_queue *queue = getQueue();
	std::string input;
	while (1) {
		std::cout << BLUE << "Choose option:\n" <<
				  "1 - check empty queue or not\n" <<
				  "2 - check full queue or not\n" <<
				  "3 - push new element to queue\n" <<
				  "4 - pop element from queue\n" <<
				  "5 - print all data from stack\n" <<
				  "6 - exist\n====>" << DEFAULT << std::endl;
		std::cin >> input;
		if (input == "1")
			std::cout << "Queue is empty? " << isEmpty(queue) << std::endl;
		else if (input == "2")
			std::cout << "Queue is full? " << isFull(queue) << std::endl;
		else if (input == "3") {
				std::cout << "Enter a number: ";
				std::cin >> input;
				push(queue, std::stoi(input));
		}
		else if (input == "4")
			pop(queue);
		else if (input == "5")
			printQueuesData(queue);
		else if (input == "6") {
			clear(queue);
			std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
			exit(0);
		}
		else {
			std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
		}
	}
}