//
// Created by tanzilya on 02.05.2021.
//

#include <iostream>
# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

int m = 17, cmp = 0;
std::string* table = new std::string[m];

std::string keys[] = {"Petrov", "Ivanov", "Rahimov", "Nikitin", "Polin", "Akimov" };

void fillEmptyArray() {
    for (int i = 0; i < m; i++) {
        table[i] = "----";
    }
}

bool isKeyInTable(std::string key) {
    bool findKey = false;
    for (int i = 0; i < m; i++) {
        if (key == keys[i]) {
            findKey = true;
            break;
        }
    }
    return findKey;
}

int getCode(std::string key) {
    int tmpCode = 0;
    for (int i = 0; i < key.length(); i++)
        tmpCode += (int)key[i];
    tmpCode = tmpCode % m;
    return tmpCode;
}


void addElement(std::string str) {
    int code;
    if (isKeyInTable(str)) {
        code = getCode(str);
        cmp++;
        if (table[code] == "----") {
            table[code] = str;
            std::cout << GREEN << "Key successfully added" << DEFAULT << std::endl;
        }
        else {
            cmp++;
            if (table[code] != str) {
                int j, i;
                for (i = 1; i < m; i++) {
                    j = (code + i) % m;
                    cmp++;
                    if (table[j] == "----") {
                        table[j] = str;
                        std::cout << GREEN << "Key successfully added" << DEFAULT << std::endl;
                        break;
                    }
                }
            }
        }
    } else std::cout << RED << "Can't add such element" << DEFAULT << std::endl;
    std::cout << "Count of compares: " << cmp << "\n";
    cmp = 0;
}

void printArray(std::string* array) {
    for (int i = 0; i < m; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void searchElement(std::string str) {
    int code = getCode(str);
    cmp++;
    if (table[code] == "----") std::cout << RED << "Can't find such element\n" << DEFAULT;
    else {
        cmp++;
        if (table[code] == str) std::cout << GREEN << "value found \n" << DEFAULT;
        else {
            bool isNotInTable = true;
            for (int i = 0; i < m; i++) {
                cmp++;
                if (table[i] == str) {
                    std::cout << GREEN <<"value found \n" << DEFAULT;
                    isNotInTable = false;
                }
            }
            if (isNotInTable) std::cout << RED << "Can't find such element\n" << DEFAULT;
        }
    }
    std::cout << "Count of cmp: " << cmp << "\n";
    cmp = 0;
}

int main() {
    fillEmptyArray();
    std::string str, input;
    while (true) {
        std::cout << BLUE << "Choose command: \n" <<
         "1)Add element\n" <<
         "2)Print table\n" <<
         "3)Search keys\n" <<
         "0)exit\n" << DEFAULT ;
        std::cout << "keys:\n";
        for (int i = 0; i < 6; i++)
            std::cout << keys[i] << " ";
        std::cout << "\n";
        std::cout << "====>";
        std::cin >> input;
        if (input == "1"){
            std::cout << "Input string:\n"; std::cin >> str;
            addElement(str);
        }
        else if (input == "2") printArray(table);
        else if (input == "3") {
            std::cout << "Input string\n"; std::cin >> str;
            searchElement(str);
        }
        else if (input == "0") break;
        else std::cout << RED << "Incorrect command" << DEFAULT << std::endl;
    }
}