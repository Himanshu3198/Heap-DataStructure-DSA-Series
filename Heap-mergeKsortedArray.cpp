// Expected Time Complexity: O(nk Logk)
// Expected Auxiliary Space: O(k)

// Merge k Sorted Arrays 
#include <bits/stdc++.h>
using namespace std;
int main()
{
   int k = 4;
    int arr[k][k] = {{1, 2, 3, 4}, {2, 2, 3, 4},
                   {5, 5, 6, 6},
                   {7, 8, 9, 9}};

 

    vector<int> vec;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {

            pq.push(arr[i][j]);
            if (pq.size() > k)
            {
                vec.push_back(pq.top());
                pq.pop();
            }
        }
    }

    while (pq.empty() == false)
    {
        vec.push_back(pq.top());
        pq.pop();
    }

    for (auto it : vec)
    {
        cout << it << " ";
    }
}
