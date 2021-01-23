#include <bits/stdc++.h>
using namespace std;

void method1()
{

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);
    pq.push(10);
    pq.push(2);
    pq.push(8);
    pq.push(102);
    pq.push(22);

    while (pq.empty() == false)
    {
        /* code */
        cout << pq.top() << " ";
        pq.pop();
    }
}
   void method2(){

       int arr[]={25, 7, 9, 15, 20, 36, 50};
       int n=sizeof(arr)/sizeof(arr[0]);
       priority_queue<int> pq;

       // multiply -1 with all element while inserting
       for(int i=0;i<n;i++)
       {
           pq.push(arr[i]*(-1));
       }
    
         // multiply all elements with -1 while
    // retrive the elements

         while (!pq.empty()) {
        cout << (pq.top()) * (-1) << " ";
        pq.pop();
    }
   }
int main()
{

    method1();
    cout<<"\n";
    method2();
}