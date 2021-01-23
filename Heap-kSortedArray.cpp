// time complexity O(nlogK).

// sort K sorted array
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={6, 5, 3, 2, 8, 10, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    vector<int> vec;
     
     priority_queue<int, vector<int>, greater<int>> pq;


     for(int i=0;i<n;i++){
         pq.push(arr[i]);
         if(pq.size()>k){
             vec.push_back(pq.top());
             pq.pop();
         }
     }
     while(pq.empty()==false){
         vec.push_back(pq.top());
        pq.pop();

     }

     for(auto it:vec){
         cout<<it<<" ";
     }




  
 
}
