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

int chan, cmp;

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
    chan++;
}


//QUICK SORT
int partition (int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        cmp++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Heap sort
void heapify(int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
    cmp += 3;
}

void heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int shellSort(int *arr, int n) {
    cmp = 0, chan = 0;
    int *copy = new int[n];
    copyOfArray(n, arr, copy);
    std::cout << "table before:\n";
    printArray(n, arr);
    std::cout << GREEN << "Starting sorting by shell sort..." << DEFAULT << std::endl;
    int temp=0, i = 0, j = 0, k = 0;
    int t = (log(n)/log(2) - 1);
    int h[] = { 1, 3, 5, 9, 17, 33, 65, 129, 257, 513, 1025, 2049, 4097, 8194 };
    for (int m = t - 1; m > -1; m--) {
        k = h[m];
        for (i = k; i < n; i++) {
            temp = copy[i];
            j = i-k;
            cmp++;
            while (j > -1 && temp < copy[j]) {
                copy[j + k] = copy[j];
                if (j != i - k)
                    chan++;
                j = j - k;
                cmp++;
            }
            if (copy[j + 1] == temp)
                chan--;
            copy[j + k] = temp;
            chan++;
        }
    }
    std::cout << "table after:\n";
    printArray(n, copy);
    delete[] copy;
    std::cout << GREEN "Compares: " << cmp << std::endl << "Changes: " << chan << std::endl;
    return 0;
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
    int i, j, min_idx, k = 0;
    int cmp = 0, chan = 0;
    int *copy = new int[n];
    copyOfArray(n, arr, copy);
    std::cout << "table before:\n";
    printArray(n, arr);
    std::cout << GREEN << "Starting sorting by selection sort..." << DEFAULT << std::endl;

    for (i=0; i < n; i++) {
        k = i; min_idx = copy[i];
        for (j = i+1; j < n; j++) {
            if (copy[j] < min_idx) {
                k = j; min_idx = copy[j];
            }
            cmp++;
        }
        if (copy[i] == min_idx)
            chan--;
        copy[k] = copy[i];
        copy[i] = min_idx;
        chan++;
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
        "5 - sort by quick sort\n" <<
        "6 - sort by shell sort\n" <<
        "7 - sort by heap sort\n" <<
        "8 - print array\n" <<
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
        else if (input == "5") {
            cmp = 0; chan = 0;
            int *copy = new int[n];
            copyOfArray(n, array, copy);
            std::cout << "table before:\n";
            printArray(n, array);
            quickSort(copy, 0, n - 1);
            std::cout << "table after:\n";
            printArray(n, copy);
            delete[] copy;
            std::cout << GREEN "Compares: " << cmp << std::endl << "Changes: " << chan << std::endl;
        }
        else if (input == "6") shellSort(array, n);
        else if (input == "7") {
            cmp = 0; chan = 0;
            int *copy = new int[n];
            copyOfArray(n, array, copy);
            std::cout << "table before:\n";
            printArray(n, array);
            heapSort(copy,n);
            std::cout << "table after:\n";
            printArray(n, copy);
            delete[] copy;
            std::cout << GREEN "Compares: " << cmp << std::endl << "Changes: " << chan << std::endl;
        }
        else if (input == "8") printArray(n, array);
        else if (input == "0") {
            delete[] array;
            break;
        }
        else std::cout << RED << "Incorrect command:(" << DEFAULT << std::endl;
    }
}