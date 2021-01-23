#include <bits/stdc++.h>
using namespace std;

int main()
{
    // create max heap
    priority_queue<int> pq;

    pq.push(5);
    pq.push(10);
    pq.push(15);
    pq.push(20);
    pq.push(25);

    // pop top item for printing element of queue

    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}