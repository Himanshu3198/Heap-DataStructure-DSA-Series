#include<bits/stdc++.h>
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
       
       priority_queue<pair<int,char>>maxHeap;
        if(a)
        maxHeap.push({a,'a'});
        if(b)
        maxHeap.push({b,'b'});
        if(c)
        maxHeap.push({c,'c'});
        string ans = "";
        char lastChar='$',secondLastChar='^';
        while(maxHeap.size()>0){
          
          auto [count, ch] = maxHeap.top();
          maxHeap.pop();
          if(ch == lastChar && lastChar == secondLastChar){
            if(maxHeap.size()==0) break;
            auto [count2, ch2] = maxHeap.top();
            maxHeap.pop();
            secondLastChar = lastChar;
            lastChar = ch2;
            ans+=ch2;
            maxHeap.push({count,ch});
            if(--count2 > 0)
               maxHeap.push({count2,ch2});
            
          }else{
            ans+=ch;
            secondLastChar = lastChar;
            lastChar = ch;
            if(--count > 0)
              maxHeap.push({count,ch});
          }
          
        }      
      return ans;
    }
};
