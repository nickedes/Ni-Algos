/*
Problem : https://www.hackerrank.com/challenges/maximise-sum
 */
#include<iostream>
using namespace std;
 
int maxSubArraySum(int a[], int size, int m)
{
    int max_so_far = 0, max_ending_here = 0;
 
    for (int i = 0; i < size; i++)
    {
        max_ending_here = (max_ending_here + a[i]) % m;
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
 
/*Driver program to test maxSubArraySum*/
int main()
{
    int tests;

    cin >> tests;

    for (int i = 0; i < tests; ++i)
    {
        int a[100], m, n;
        cin >> n >> m;
        for (int j = 0; j < n; ++j)
            cin >> a[j];
        int max_sum = maxSubArraySum(a, n, m);
        cout << max_sum << endl;
    }
    return 0;
}