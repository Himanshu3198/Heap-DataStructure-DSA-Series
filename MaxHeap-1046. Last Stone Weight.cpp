
//  time complexity O(n)+log(n)
//  space complexity O(n)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int,vector<int>>pq;
        for(auto it:stones){
            pq.push(it);
        }
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(first!=second){
                pq.push(first-second);
            }
        }
        
        return pq.size()==0?0:pq.top();
    }
};
