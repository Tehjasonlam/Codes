#include <iostream>
#include <string>

using namespace std;

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bubbleSortRecursive(int arr[], int n) {
    if (n == 0 || n == 1) {
        return;
    }
    int i, j;
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(&arr[i], &arr[i + 1]);
        }
    }
    bubbleSortRecursive(arr, n - 1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// bubble sort is a comparison sort algorithm. It repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. 
//The pass through the list is repeated until the list is sorted.
// Inefficient larger the data set.
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printArray(arr, n);

    int arr1[] = {64, 34, 25, 12, 22, 11,  90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSortRecursive(arr1, n1);
    printArray(arr1, n1);

    return 0;
}
