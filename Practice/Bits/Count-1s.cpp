/*
write a program to determine the number of 1's in its binary representation 
 */
#include <iostream>
using namespace std;

int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  int i = 1;
  while(n)
  {
    count += n & 1;
    n >>= 1;
    cout << i++;
  }
  return count;
}
 
/* Program to test function countSetBits */
int main()
{
    int i = 100;
    cout << endl << countSetBits(i);
    return 0;
}