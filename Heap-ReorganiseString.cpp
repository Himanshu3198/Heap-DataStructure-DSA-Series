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


// java code

class Pair implements Comparable<Pair>{
    Character c;
    Integer count;

    public Pair(Character c, Integer count){
        this.c = c;
        this.count = count;
    }

    public void updateCount(){
        this.count = this.count-1;
    }

    @Override
    public int compareTo(Pair other){

        return Integer.compare(other.count,this.count);
    }
}
class Solution {
    public String reorganizeString(String s) {
        
        Map<Character,Integer> freq = new HashMap<>();
        for(int i=0;i<s.length();i++){
            Character c = s.charAt(i);
            freq.put(c,freq.getOrDefault(c,0)+1);
        }

        PriorityQueue<Pair> maxHeap = new PriorityQueue<>();

        for(Map.Entry<Character,Integer> x :freq.entrySet()){

            maxHeap.add(new Pair(x.getKey(),x.getValue()));
        }

        StringBuilder ans = new StringBuilder();
        while(maxHeap.size()>1){

            Pair first = maxHeap.poll();
            Pair second = maxHeap.poll();

            if(first.count > 0){
                ans.append(first.c);
                first.updateCount();
                if(first.count > 0){
                    maxHeap.add(first);
                }
            }

            if(second.count > 0){
                ans.append(second.c);
                second.updateCount();
                if(second.count > 0){
                    maxHeap.add(second);
                }
            }

        }

        if(!maxHeap.isEmpty()){

            Pair last = maxHeap.poll();
            if(last.count >1) return "";
            ans.append(last.c);
            last.updateCount();
        }
        return ans.toString();
    }
}
