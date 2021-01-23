#include<bits/stdc++.h>
using namespace std;

int main(){
  
    int arr[]={7 ,10, 4, 20, 15};
     int k=4;
     int n=sizeof(arr)/sizeof(arr[0]);
      priority_queue<int>pq;
     for(int i=0;i<n;i++){
         pq.push(arr[i]);
         if(pq.size()>k){
             pq.pop();
         }
     }
     cout<<pq.top()<<"\n";

     

  
}