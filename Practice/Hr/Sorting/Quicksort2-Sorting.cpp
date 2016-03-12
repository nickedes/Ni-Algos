/*
Problem : https://www.hackerrank.com/challenges/quicksort2
 */

#include <iostream>
using namespace std;

int print_array(int arr[], int begin, int end) {
    for (int i = begin; i < end; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

int partition(int begin, int end, int arr[]) {
    int insert;
    int pivot = begin;
    for (int i=pivot+1; i<end; i++) {
        if (arr[i] < arr[pivot]) {
            insert = arr[i];
            for(int j=i; j>pivot; j--) {
                arr[j] = arr[j-1];
            }
            arr[pivot] = insert;
            pivot++;
        }
    }
    if (pivot - begin > 1) {
        partition(begin, pivot, arr);
    }
    if (end - pivot > 2) {
        partition(pivot+1, end, arr);
    }
    return print_array(arr, begin, end);
}

int quickSort(int arr[], int size) {
   return partition(0, size, arr);
}

/* Tail starts here */
int main() {

    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];

    quickSort(arr, size);

    return 0;
}