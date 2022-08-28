class Solution {
public:
    int fillCups(vector<int>& amount) {
        
         priority_queue<int,vector<int>>maxHeap;
         for(auto v:amount) if(v>0) maxHeap.push(v);
         int res=0;
         while(!maxHeap.empty() && maxHeap.size()>1){
             
             int first=maxHeap.top();
             maxHeap.pop();
             int second=maxHeap.top();
             maxHeap.pop();
             if(--first>0)maxHeap.push(first);
             if(--second>0)maxHeap.push(second);
             res++;
         }
        res+=maxHeap.size()>0?maxHeap.top():0;
        return res;
    }
};
