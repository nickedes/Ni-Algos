#include <iostream>
#include <stdio.h>
using namespace std;

#define SIZE 1001
 
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
 
    int n, arr[SIZE];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int p = arr[0];
    int left[SIZE], right[SIZE], j=0, k=0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= p)
        {
            right[k++] = arr[i];
        }
        else
        {
            left[j++] = arr[i];
        }
    }
    for (int i = 0; i < j; ++i)
        cout << left[i] << " ";
    for (int i = 0; i < k; ++i)
        cout << right[i] << " ";
    return 0;
}