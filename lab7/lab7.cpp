#include "ft_list.h"
# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

void printOneList(ft::list<int> const * list) {
	if (list->empty()) {
		std::cout << RED << "List is empty:(" << DEFAULT << std::endl;
		return;
	}
	for (auto i = list->begin(); i != list->end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}

void printList(ft::list < std::pair <std::string, ft::list<int> *> > const & list) {
	if (list.empty()) {
		std::cout << RED << "List is empty:(" << DEFAULT << std::endl;
		return;
	}
	std::cout << GREEN << "Printing all lists..." << DEFAULT << std::endl;
	for (auto i = list.begin(); i != list.end(); ++i) {
		std::cout << i->first << std::endl;
		printOneList(i->second);
	}
}

void printNamesOfLists(ft::list < std::pair <std::string, ft::list<int> *> > const & list) {
	if (list.empty()) {
		std::cout << RED << "List is empty:(" << DEFAULT << std::endl;
		return;
	}
	for (auto i = list.begin(); i != list.end(); ++i) {
		std::cout << i->first  << std::endl;
	}
}

void workWithDefiniteList(ft::list<int> *list) {
	std::string input;
	std::string tmp;
	ft::list<int> :: iterator i;
	while (1) {
		std::cout << BLUE << "Choose option:\n" <<
				  "1 - push element back\n" <<
				  "2 - push element front\n" <<
				  "3 - push element before...\n" <<
				  "4 - push element after...\n" <<
				  "5 - pop element\n" <<
				  "6 - print all list's data\n" <<
				  "7 - exist from menu of this list\n====>" << DEFAULT << std::endl;
		std::cin >> input;
		if (input == "1") {
			std::cout << "Input data: ";
			std::cin >> input;
			list->push_back(std::stoi(input));
		}
		else if (input == "2") {
			std::cout << "Input data: ";
			std::cin >> input;
			list->push_front(std::stoi(input));
		}
		else if (input == "3") {
			std::cout << "Input data: ";
			std::cin >> input;
			std::cout << "Input element: ";
			std::cin >> tmp;
			for (i = list->begin(); *i != std::stoi(tmp); ++i);
			list->insert(i, std::stoi(tmp));
		}
		else if (input == "4") {
			std::cout << "Input data: ";
			std::cin >> input;
			std::cout << "Input element: ";
			std::cin >> tmp;
			for (i = list->begin(); *i != std::stoi(tmp); ++i);
			list->insert(++i, std::stoi(tmp));
		}
		else if (input == "5") {
			std::cout << "Input element: ";
			std::cin >> tmp;
			for (i = list->begin(); *i != std::stoi(tmp); ++i);
			list->erase(i);
		}
		else if (input == "6")
			printOneList(list);
		else if (input == "7") {
			return;
		}
		else
			std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
	}
}


int main() {
	ft::list < std::pair <std::string, ft::list<int> *> > myList;
	ft::list < std::pair <std::string, ft::list<int> *> >::iterator i;
	std::string input;
	std::string tmp;
	while (1) {
		std::cout << BLUE << "Choose option:\n" <<
				  "1 - print all lists\n" <<
				  "2 - push new list front\n" <<
				  "3 - push new list back\n" <<
				  "4 - pop back\n" <<
				  "5 - pop front\n" <<
				  "6 - push new list after...\n" <<
				  "7 - push new list before...\n" <<
				  "8 - work with definite list\n" <<
				  "9 - pop definite list\n" <<
				  "10 - exist\n====>" << DEFAULT << std::endl;
		std::cin >> input;
		if (input == "1") {
			printList(myList);
		}
		else if (input == "2") {
			std::cout << "Give name for list: ";
			std::cin >> input;
			myList.push_front(std::pair<std::string, ft::list<int> *>(input, new ft::list<int>));
		}
		else if (input == "3") {
			std::cout << "Give name for list: ";
			std::cin >> input;
			ft::list<int> t;
			myList.push_back(std::pair<std::string, ft::list<int> *>(input, new ft::list<int>));
		}
		else if (input == "4") {
			myList.pop_back();
		}
		else if (input == "5")
			myList.pop_front();
		else if (input == "6") {
			std::cout << "Choose the list, after which you would like to push new list..." << std::endl;
			printNamesOfLists(myList);
			std::cin >> input;
			for (i = myList.begin(); i->first != input; ++i);
			std::cout << "Give name for list: ";
			std::cin >> input;
			myList.insert(++i, std::pair<std::string, ft::list<int>*>(input, new ft::list<int>));
		}
		else if (input == "7") {
			std::cout << "Choose the list, before which you would like to push new list..." << std::endl;
			printNamesOfLists(myList);
			std::cin >> input;
			ft::list<int> t;
			for (i = myList.begin(); i->first != input; ++i);
			std::cout << "Give name for list: ";
			std::cin >> input;
			myList.insert(i,std::pair<std::string, ft::list<int>*>(input, new ft::list<int>));
		}
		else if (input == "8") {
			std::cout << "Choose the list.." << std::endl;
			printNamesOfLists(myList);
			std::cin >> input;
			for (i = myList.begin(); i->first != input; ++i);
			workWithDefiniteList(i->second);
		}
		else if (input == "9") {
			std::cout << "Choose the list.." << std::endl;
			printNamesOfLists(myList);
			std::cin >> input;
			for (i = myList.begin(); i->first != input; ++i);
			myList.erase(i);
		}
		else if (input == "10") {
			myList.clear();
			std::cout << GREEN << "See you soon!" << DEFAULT << std::endl;
			exit(0);
		}
		else {
			std::cout << RED << "Incorrect command :(" << DEFAULT << std::endl;
		}
	}
}
