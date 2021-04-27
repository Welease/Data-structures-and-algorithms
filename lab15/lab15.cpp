//
// Created by tanzilya on 24.04.2021.
//

# define BLUE "\e[34m"
# define DEFAULT "\e[39m\e[0m"
# define GREEN "\e[92m"
# define RED  "\e[31m"

#include <iostream>
#include <cstdlib>
#include <cmath>

int max = 0;

struct listNode {
    int key = -1;
    listNode *next = nullptr, *tail = nullptr;
};

listNode *ls = nullptr, *head = nullptr;

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


void bucketSort(int n, int *array) {
    int *copy;

    copy = new int[n];
    copyOfArray(n, array, copy);
    int temp; std::string input;
    std::cout << "Array before: " << std::endl;
    printArray(n, array);
    std::cout << "Sort with second array? \n 1 - yes, 0 - no\n"; std::cin >> input;
    std::cout << "Array after: " << std::endl;
    if (input == "0") {
        for (int i = 0; i < n; i++) {
            while (copy[i] != i) {
                temp = copy[copy[i]];
                copy[copy[i]] = copy[i];
                copy[i] = temp;
            }
        }
        printArray(n, copy);
        delete [] copy;
    }
    else {
        int *result = new int[n];
        for (int i = 0; i < n; i++) {
            result[copy[i]] = copy[i];
        }
        delete [] copy;
        printArray(n, result);
    }
}

void eraseList(listNode *node) {
    if (node->next)
        eraseList(node->next);
    delete node;
}

int *toArray(listNode *head, int n) {
    listNode *cur = head;
    int *c = new int[n];
    for (int i = 0; i < n; i++) {
        c[i] = cur -> key;
        cur = cur -> next;
    }
    return c;
}


listNode *combining(listNode *node) {
    listNode *head = new listNode;
    head -> key = node[0].key;
    head -> next = node[0].next;
    head -> tail = node[0].tail;
    listNode *cur = head;
    for (int i = 0; i < max - 1; i++) {
        if (node[i].tail)
            cur = node[i].tail;
        cur -> next = new listNode;
        cur = cur -> next;
        cur -> key = node[i + 1].key;
        cur -> next = node[i + 1].next;
        cur -> tail = node[i + 1].tail;
    }
    return head;
}


void bucketSortGEN(int *arr, int n) {
    int *copy = new int[n];
    std::cout << "Array before: " << std::endl;
    printArray(n, arr);
    copyOfArray(n, arr, copy);
    ls = new listNode[max];
    for (int i = 0; i < n; i++) {
        if (ls[copy[i]].key == -1)
            ls[copy[i]].key = copy[i];
        else if (!ls[copy[i]].next) {
            ls[copy[i]].next = new listNode;
            ls[copy[i]].tail = ls[copy[i]].next;
            ls[copy[i]].next->key = copy[i];
        }
        else if (!ls[copy[i]].tail->next) {
            ls[copy[i]].tail->next = new listNode;
            ls[copy[i]].tail->next->key = copy[i];
            ls[copy[i]].tail = ls[copy[i]].tail->next;
        }
    }
    head = combining(ls);
    copy = toArray(head, n);
    head = nullptr;
    std::cout << "Array after:\n";
    printArray(n, copy);
    delete [] copy;
    delete [] ls;
}


//RADIX SORT
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


void countSort(int *arr, int n, int exp) {
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int *arr, int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void formArrayToBucketSort(int *&arr, int & n) {
    std::cout << "Input count of elements for new array: "; n = checkInput();
    delete[] arr;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    int tmp, r;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        r = rand() % n;
        tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
    }
}

void formArrayToBucketSortGEN(int *&arr, int & n) {
    std::cout << "Input count of elements for new array: "; n = checkInput();
    delete[] arr;
    arr = new int[n];
    max = n - n / 3;
    for (int i = 0; i < max; ++i) {
        arr[i] = i;
    }
    for (int i = max; i < n; ++i)
        arr[i] = rand() % max;
    int tmp, r;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        r = rand() % n;
        tmp = arr[i];
        arr[i] = arr[r];
        arr[r] = tmp;
    }
}

int main() {
    std::string input;
    int *array = nullptr, n;
    srand(time(nullptr));
    while (true) {
        std::cout << BLUE << "Choose option:\n" <<
        "1 - form new mass\n" <<
        "2 - sort by radix sort\n" <<
        "3 - sort by bucket sort\n" <<
        "4 - sort by gen bucket sort\n" <<
        "0 - exit\n" <<
        "====>" << DEFAULT ;
        std::cin >> input;
        if (input == "1") {
            std::cout << "Input count of elements: "; n = checkInput();
            delete[] array;
            array = new int[n];
            fillArray(n, array);
        }
        else if (input == "2") {
            int *copy = new int[n];
            copyOfArray(n, array, copy);
            std::cout << "Array before:\n";
            printArray(n, array);
            radixsort(copy, n);
            std::cout << "Array after:\n";
            printArray(n, copy);
            delete[] copy;
        }
        else if (input == "3") {
            formArrayToBucketSort(array, n);
            bucketSort(n, array);
        }
        else if (input == "4") {
            formArrayToBucketSortGEN(array, n);
            bucketSortGEN(array, n);
        }
        else if (input == "8") printArray(n, array);
        else if (input == "0") {
            delete[] array;
            break;
        }
        else std::cout << RED << "Incorrect command:(" << DEFAULT << std::endl;
    }
}