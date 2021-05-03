//
// Created by tanzilya on 02.05.2021.
//

#include <iostream>
# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

int m = 11, cmp = 0;

//std::string keys[] = {"Petrov", "Ivanov", "Rahimov", "Nikitin", "Polin", "Akimov", "Olegov", "Salikov"};

struct Hash{
    Hash* next = nullptr;
    Hash* prev = nullptr;
    std::string value = "----";
}*List;


void initTab() {
    List = new Hash[m];
}

int getCode(std::string key) {
    int code = 0;
    for (int i = 0; i < key.length(); i++)
        code += (int)key[i];
    code = code % m;
    return code;
}

bool search(std::string & str, bool print) {
    int tmp = getCode(str);
    cmp++;
    if (List[tmp].value == str) {
        if (print)
            std::cout << GREEN << "Element is in " << tmp + 1 << " box\n" << DEFAULT;
        return true;
    }
    else if (List[tmp].next) {
        Hash* Current = List[tmp].next;
        int i = 0;
        while (Current) {
            cmp++;
            if (Current->value == str) {
                if (print)
                    std::cout << GREEN << "Element is in " << tmp + 1 << " box in " << i + 1 << " position\n" << DEFAULT;
                return true;
            }
            Current = Current->next;
            i++;
        }
    }
    else {
        if (print)
            std::cout << RED << "Can't find such key" << DEFAULT << std::endl;
    }
    if (print) {
        std::cout << "Count of compares: " << cmp << "\n";
    }
    cmp = 0;
    return false;
}

void insert(std::string & str) {
    int code;
        code = getCode(str);
        if (search(str, false)) {
            std::cout << RED << "Key in table" << DEFAULT << std::endl;
            return ;
        }
        cmp++;
        if (List[code].value == "----") {
            List[code].value = str;
            std::cout << GREEN << "Key successfully added" << DEFAULT << std::endl;
        }
        else {
            cmp++;
            if (List[code].value != str) {
                cmp++;
                if (!List[code].next) {
                    List[code].next = new Hash;
                    List[code].next->value = str;
                    List[code].prev = List[code].next;
                }
                else {
                    List[code].prev->next = new Hash;
                    List[code].prev->next->value = str;
                    List[code].prev = List[code].prev->next;
                }
            }
        }
    std::cout << "Count of compares: " << cmp << "\n";
    cmp = 0;
}

void printTable() {
    for (int i = 0; i < m; i++) {
        std::cout << List[i].value << ": ";
        if (List[i].next) {
            Hash* tmp = List[i].next;
            while (tmp) {
                std::cout << tmp->value << "; ";
                tmp = tmp->next;
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void erase(std::string & str) {
    int code = getCode(str);
    if (List[code].value == str) {
        if (!List[code].next)
            List[code].value = "----";
        else {
            Hash* Current = List[code].next;
            List[code].value = Current->value;
            List[code].next = Current->next;
            delete Current;
        }
    }
    else if (List[code].next) {
        Hash* tmp = List[code].next;
        int i = 0;
        while (tmp) {
            if (tmp->value == str) break;
            i++;
            tmp = tmp->next;
        }
        if (i == 0) {
            List[code].next = tmp->next;
            delete tmp;
        }
        else {
            Hash* prev = List[code].next;
            while (prev != tmp) {
                if (prev->next == tmp) break;
                prev = prev->next;
            }
            prev->next = tmp->next;
            delete tmp;
        }
    }
}

int main() {
    initTab();
    std::string str, input;
    while (true) {
        std::cout << BLUE << "Choose option:\n" <<
        "1)Add element\n" <<
        "2)Print table\n" <<
        "3)Search element\n" <<
        "4)Delete element\n" <<
        "0)Exit\n"  << DEFAULT << std::endl;

        std::cout << "====>"; std::cin >> input;
        if (input == "1") {
            std::cout << "Input string:\n"; std::cin >> str;
            insert(str);
        }
        else if (input == "2") printTable();
        else if (input == "3") {
            std::cout << "Input string:\n"; std::cin >> str;
            search(str, true);
        }
        else if (input == "4") {
            std::cout << "Input string:\n"; std::cin >> str;
            erase(str);
        }
        else if (input == "0") break;
        else std::cout << RED << "Incorrect command" << DEFAULT << std::endl;
    }
}