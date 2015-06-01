/*
Sorting a list of dates.
 */
#include <iostream>
using namespace std;

struct date
{
	int d, m, y;
};
// Cs - Count Sort
void CsDay(date array[], int n);
void CsMonth(date array[], int n);
void CsYear(date array[], int n);
// Rs - Radix Sort
void RsDates(date array[], int n)
{
	CsDay(array,n);
	CsMonth(array,n);
	CsYear(array,n);
}

void CsDay(date array[], int n)
{
	date output[n];
	int i, count[31] = {0};

	for (i = 0; i < n ; i++)
		count[array[i].d - 1]++;
 	
 	for (i=1; i<31; i++)
        count[i] += count[i-1];

    for (i=n-1; i>=0; i--)
    {
        output[count[array[i].d - 1] - 1] = array[i];
        count[array[i].d - 1]--;
    }

    for (i=0; i<n; i++)
        array[i] = output[i];
}

void CsMonth(date array[], int n)
{
    date output[n]; // output array
    int i, count[12] = {0};
 
    for (i = 0; i < n; i++)
        count[array[i].m - 1]++;
    for (i = 1; i < 12; i++)
        count[i] += count[i - 1];
    for (i=n-1; i>=0; i--)
    {
        output[count[array[i].m - 1] - 1] = array[i];
        count[array[i].m - 1]--;
    }
    for (i = 0; i < n; i++)
        array[i] = output[i];
}

void CsYear(date array[], int n)
{
    date output[n]; // output array
    int i, count[1000] = {0};
    for (i = 0; i < n; i++)
        count[array[i].y - 2000]++;
    for (i = 1; i < 1000; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[array[i].y - 2000] - 1] = array[i];
        count[array[i].y - 2000]--;
    }
    for (i = 0; i < n; i++)
        array[i] = output[i];
}

void print(date array[], int n)
{
    int i;
    for (i=0; i<n; i++)
        cout <<"{" << array[i].d <<", "<<array[i].m <<", "<<array[i].y<<"}\n";
}

int main()
{
    date arr[] = {{20, 1, 2014}, {25, 3, 2010},
                  {3, 12, 2000}, {18, 11, 2001},
                  {19, 4, 2015}, {9, 7, 2005}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Input Dates\n";
    print(arr, n);
    RsDates(arr, n);
    cout << "\nSorted Dates\n";
    print(arr, n);
    return 0;
}