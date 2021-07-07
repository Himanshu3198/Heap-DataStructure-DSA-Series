// 506. Relative Ranks


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>res(score.size(),"");
        
        priority_queue<pair<int,int>>pq;
        
        
            for(int i=0;i<score.size();i++){
            
            pq.push({score[i],i});
        }
           int count=0;
        
              
            for (int i=0;i<score.size();i++) {
                
     
        
    if (i==0) res[pq.top().second] = "Gold Medal";
    else if (i==1) res[pq.top().second] = "Silver Medal";
    else if (i==2) res[pq.top().second] = "Bronze Medal";
    else res[pq.top().second] = to_string(i+1);
                
                  pq.pop();
                
     }
                
          
     
        return res;
    }
};
