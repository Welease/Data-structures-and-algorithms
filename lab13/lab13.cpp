//
// Created by tanzilya on 24.04.2021.
//

# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

#include <iostream>
#include <cstdlib>

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int checkInput() {
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n')) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << RED << "Incorrect input, please try again: " << DEFAULT;
    }
    return a;
}

void printArray(int n, int *array) {
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl << std::endl;
}

void copyOfArray(int n, int *from, int *to) {
    for (int i = 0; i < n; ++i)
        to[i] = from[i];
}

void fillArray(int n, int *array) {
    for (int i = 0; i < n; ++i)
        array[i] = getRandomNumber(0, 10000);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int *arr, int n) {
    int cmp = 0, chan = 0;
    int *copy = new int[n];
    copyOfArray(n, arr, copy);
    std::cout << "table before:\n";
    printArray(n, arr);
    std::cout << GREEN << "Starting sorting by bubble sort..." << DEFAULT << std::endl;
    for (int i = 0; i < n - 2; i++)
        for (int j = 0; j < n - i - 1; j++) {
            cmp++;
            if (copy[j] > copy[j + 1]) {
                swap(&copy[j], &copy[j + 1]);
                ++chan;
            }
        }
    std::cout << "table after:\n";
    printArray(n, copy);
    delete[] copy;
    std::cout <<GREEN "Compares: " << cmp << std::endl << "Changes: " << chan << std::endl;
}

void selectionSort(int *arr, int n) {
    int i, j, min_idx;
    int cmp = 0, chan = 0;
    int *copy = new int[n];
    copyOfArray(n, arr, copy);
    std::cout << "table before:\n";
    printArray(n, arr);
    std::cout << GREEN << "Starting sorting by selection sort..." << DEFAULT << std::endl;

    for (i=0; i < n - 1; i++) {
       min_idx = i;
        for (j = i+1; j < n; j++) {
            if (copy[j] < copy[min_idx]) {
                min_idx = j;
            }
            cmp++;
        }
        if (min_idx != i) {
            int tmp = copy[i];
            copy[i] = copy[min_idx];
            copy[min_idx] = tmp;
            chan++;
        }
    }
    std::cout << "table after:\n";
    printArray(n, copy);
    delete[] copy;
    std::cout <<GREEN "Compares: " << cmp << std::endl << "Changes: " << chan << std::endl;
}

void insertionSort(int *arr, int n) {
    int i, key, j;
    int cmp = 0, chan = 0;
    int *copy = new int[n];
    copyOfArray(n, arr, copy);
    std::cout << "table before:\n";
    printArray(n, arr);
    std::cout << GREEN << "Starting sorting by insertion sort..." << DEFAULT << std::endl;
    for (i = 1; i < n; i++) {
        key = copy[i];
        j = i - 1; cmp++;
        while (j > -1 && key < copy[j]) {
            copy[j + 1] = copy[j];
            if (j != i - 1)
                chan++;
            j--; cmp++;
        }
        if (copy[j + 1] == key)
            chan--;
        copy[j+1] = key; chan++;
    }
    std::cout << "table after:\n";
    printArray(n, copy);
    delete[] copy;
    std::cout <<GREEN "Compares: " << cmp << std::endl << "Changes: " << chan << std::endl;
}

int main() {
    std::string input;
    int *array = nullptr, n;
    srand(time(nullptr));
    while (true) {
        std::cout << BLUE << "Choose option:\n" <<
        "1 - form new mass\n" <<
        "2 - sort by bubble sort\n" <<
        "3 - sort by insertion sort\n" <<
        "4 - sort by selection sort\n" <<
        "5 - print array\n" <<
        "0 - exit\n" <<
        "====>" << DEFAULT ;
        std::cin >> input;
        if (input == "1") {
            std::cout << "Input count of elements: "; n = checkInput();
            delete[] array;
            array = new int[n];
            fillArray(n, array);
        }
        else if (input == "2") bubbleSort(array, n);
        else if (input == "3") insertionSort(array, n);
        else if (input == "4") selectionSort(array, n);
        else if (input == "5") printArray(n, array);
        else if (input == "0") {
            delete[] array;
            break;
        }
        else std::cout << RED << "Incorrect command:(" << DEFAULT << std::endl;
    }
}