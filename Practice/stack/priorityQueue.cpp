// priority queue is max heap
#include <bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<int> pq;
	pq.push(5);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
	
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}
