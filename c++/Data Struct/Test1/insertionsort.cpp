#include <iostream>
#include <string>

using namespace std;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//split the array into sorted and unsorted subarrays
//pick an unsorted index and place it right in the sorted subarray
//efficient for small data sets
//more effcient if the data is partially sorted

int main() {

    return 0;
}