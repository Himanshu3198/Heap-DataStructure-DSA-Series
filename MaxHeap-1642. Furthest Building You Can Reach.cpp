class Solution {
public:
//      t.c O(n*log(n))
//      s.c O(n)
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        int i=0,n=heights.size();
        priority_queue<int,vector<int>>maxHeap;
        for(;i<n;i++){
            if(i+1<n && heights[i]>=heights[i+1]) continue;
            if(i+1<n){
            int diff=heights[i+1]-heights[i];
            if((diff)>0 && bricks>=diff){
                
                bricks-=diff;
                maxHeap.push(diff);
            }else if(ladders>0){
                
                if(!maxHeap.empty()){
                    
                    int maxDiff=maxHeap.top();
                   
                    if(maxDiff>=diff){
                             maxHeap.pop();
                             bricks+=maxDiff;
                             bricks-=diff;
                             maxHeap.push(diff);
                    }
                }
                ladders--;
            }else return i;
            }
            
        }
        return n-1;
        
    }
};
