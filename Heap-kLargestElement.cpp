// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(K*logK)

// k largest elements
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1, 23, 12, 9, 30, 2, 50};
       int k=3,n=7;
     priority_queue<int, vector<int>, greater<int>> pq;


  
      for(int i=0;i<n;i++){
             
              pq.push(arr[i]);
              if(pq.size()>k){
                  pq.pop();
              }
      }
         
       int newarr[pq.size()];
       int m=pq.size();
       int i=m-1;
    while (pq.empty() == false)
    {
        /* code */
        // cout << pq.top() << " ";
        newarr[i]=pq.top();
        pq.pop();
        i--;
    }
    for(int j=0;j<m;j++){
        cout<<newarr[j]<<" ";
    }
}


// Input:
// N = 7, K = 3
// Arr[] = {1, 23, 12, 9, 30, 2, 50}
// Output: 50 30 23
// Explanation: 3 Largest element in the
// array are 50, 30 and 23.