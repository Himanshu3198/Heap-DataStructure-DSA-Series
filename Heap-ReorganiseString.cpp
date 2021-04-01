#include <bits/stdc++.h>
using namespace std;

string reorganiseString(string s)
{
         map<char, int> mp;
    string ans;
    priority_queue<pair<int, char>> pq;

    for (auto x:s)
    {
        mp[x]++;
    }

    for (auto it : mp)
    {
        // cout<<it.first<<" "<<it.second<<"\n";
        pq.push({it.second, it.first});
    }

    while (pq.size() > 1)
    {

        auto k = pq.top();
        pq.pop();
        ans += k.second;
        k.first--;  
        auto l = pq.top();
        pq.pop();
        ans += l.second;
        l.first--;
        
          if (k.first > 0)
        {
            pq.push(k);
        }
        if (l.first > 0)
        {
            pq.push(l);
        }
       
    }
    if (pq.size() == 0)
    {
        return ans;
    }
    if (pq.top().first > 1)
    {
        return "";
    }
    return ans+pq.top().second;
}

int main()
{

    string s = "aaabcdd";

    cout << reorganiseString(s);
}