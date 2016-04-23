#include <stdio.h>
#include <iostream>
using namespace std;
#define SWAP(a, b, c)c t; t=a, a=b, b=t
int main()
{
    int a=2, b=3;
    int *x, *y;
    x=&a;
    y=&b;
    SWAP(x, y, int*);
    printf("%d %d %d %d\n",a,b, *x, *y);
    return 0;
}