#include "ft_list.h"
# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

void printOneList(ft::list<int> const list) {
	if (list.empty()) {
		std::cout << RED << "listNode is empty:(" << DEFAULT << std::endl;
		return;
	}
	for (auto i = list.begin(); i != list.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}

int main() {
	std::string input;
	std::string tmp;
	ft::list<int> list;
	ft::list<int> :: iterator i;
	while (1) {
		std::cout << BLUE << "Choose option:\n" <<
				  "1 - push element back\n" <<
				  "2 - push element front\n" <<
				  "3 - push element before...\n" <<
				  "4 - push element after...\n" <<
				  "5 - pop element\n" <<
				  "6 - print all list's data\n" <<
				  "7 - pop back\n" <<
				  "8 - pop front\n" <<
				  "9 - exist\n====>" << DEFAULT << std::endl;
		std::cin >> input;
		if (input == "1") {
			std::cout << "Input data: ";
			std::cin >> input;
			list.push_back(std::stoi(input));
		}
		else if (input == "2") {
			std::cout << "Input data: ";
			std::cin >> input;
			list.push_front(std::stoi(input));
		}
		else if (input == "3") {
			std::cout << "Input data: ";
			std::cin >> input;
			std::cout << "Input element: ";
			std::cin >> tmp;
			for (i = list.begin(); i != list.end(); ++i)
				if (*i == std::stoi(tmp))
					break;
			list.insert(i, std::stoi(input));
		}
		else if (input == "4") {
			std::cout << "Input data: ";
			std::cin >> input;
			std::cout << "Input element: ";
			std::cin >> tmp;
			for (i = list.begin(); i != list.end(); ++i)
				if (*i == std::stoi(tmp))
					break;
			list.insert(++i, std::stoi(input));
		}
		else if (input == "5") {
			std::cout << "Input element: ";
			std::cin >> tmp;
			for (i = list.begin(); *i != std::stoi(tmp); ++i);
			if (i != list.end())
				list.erase(i);
			else
				std::cout << RED << "listNode is empty" << DEFAULT << std::endl;
		}
		else if (input == "6")
			printOneList(list);
		else if (input == "7")
			if (!list.empty())
				list.pop_back();
			else
				std::cout << RED << "listNode is empty" << DEFAULT << std::endl;
		else if (input == "8")
			if (!list.empty())
				list.pop_front();
			else
				std::cout << RED << "listNode is empty" << DEFAULT << std::endl;
		else if (input == "9") {
			exit(0);
		}
		else
			std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
	}
}
