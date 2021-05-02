//
// Created by tanzilya on 02.05.2021.
//

#include <iostream>
# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

std::string *a = nullptr;
int num = 10;

std::string keys[] = {"PRIVATE", "START", "While", "RETURN", "FOR", "SWITCH", "IF", "ELSE", "THIS", "TEMPLATE"};
int checkInput() {
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << RED << "Incorrect input, please try again: " << DEFAULT;
    }
    return a;
}


std::string getString() { std::string str; std::cin >> str; return str; }

bool searchKey(std::string _key) {
    bool x = false;
    for (int i = 0; i < num; i++) {
        if (_key == keys[i]) {
            x = true;
            break;
        }
    }
    return x;
}

int codeGenerate(std::string _str) {
    int code = 0;
    for (int i = 0; i < _str.length(); i++) {
        code += (int)_str[i];
    }
    std::cout << "getCode is: " << code << std::endl;
    code = code % num;
    std::cout << "Index is: " << code << std::endl;
    return code;
}

void printArray(int *array) {
    std::cout << GREEN <<"Printing array..." << DEFAULT << std::endl;
    for (int i = 0; i < num; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

bool insert(std::string _str) {
    std::cout << "Key: " << _str << "\n";
    int code = 0;
    if (searchKey(_str)) {
        code  = codeGenerate(_str);
        if (a[code] != _str) {
            a[code] = _str;
            std::cout << GREEN << "value successfully added" << DEFAULT << std::endl;
            return true;
        }
        else
            std::cout << RED << "Such element exist" << DEFAULT << std::endl;
    }
    else
        std::cout << RED << "Can't add such element" << DEFAULT << std::endl;
    return false;
}

int main() {
    int countOfElements = 0, code = 0;
    std::string str;

    a = new std::string[num];
    for (int i = 0; i <num; i++)
        a[i] = "--empty--";

    std::string input;
    while (true) {
        std::cout << BLUE
             << "keys: PUBLIC, PRIVATE, WHILE, RETURN, FOR, SWITCH, IF, ELSE, THIS, PRIVATE\n"
             << "In table " << countOfElements << "/" << num << std::endl
             << "Choose command\n"
             << "1 - add new element\n"
             << "2 - search element\n"
             << "3 - print table\n"
             << "4 - default print\n"
             << "5 - delete element\n"
             << "0 - exit\n"
             <<"====>: " << DEFAULT; std::cin >> input;
        if (input == "1") {
            if (countOfElements < num) { std::cout <<"Input string: ";
                if (insert(getString()))
                    countOfElements++;
            }
            else std::cout << RED << "Table is full" << DEFAULT << std::endl;
        }
        else if (input == "2") {
            std::cout << "Input key: ";
            str = getString();
            code = codeGenerate(str);
            str == a[code] ? std::cout << " ЭЛЕМЕНТ НАЙДЕН В ЯЧЕЙКЕ " << code << "\n" : std::cout << " ЭЛЕМЕНТ НЕ НАЙДЕН\n";
        }
        else if (input == "3") {
            std::cout << GREEN << "In table:\n" << DEFAULT;
            for (int i = 0; i < num; i++)
                std::cout << i << ") " << a[i] << "\n";
        }
        else if (input == "4") {
            for (int i = 0; i < num; i++)
                insert(keys[i]);
            countOfElements = num;
        }
        else if (input == "5") {
            std::cout << "Input element:" ; str = getString();
            code = codeGenerate(str);
            if (str == a[code]) {
                a[code] = "--empty--";
                std::cout << GREEN << "value successfully deleted" << DEFAULT << std::endl;
                countOfElements--;
            }
            else
                std::cout << RED << "Can't find such element" << DEFAULT << std::endl;
        }
        else if (input == "0")
            break;
        else
            std::cout << RED << "Incorrect command" << DEFAULT << std::endl;
    }
    delete [] a;
    return 0;
}
