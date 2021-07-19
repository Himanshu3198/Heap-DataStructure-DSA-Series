// 1337. The K Weakest Rows in a Matrix

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         
        
        priority_queue<pair<int,int>>pq;
        
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            
            
            for(int j=0;j<m;j++){
                
                
                if(mat[i][j]==1){
                    count++;
                }
                
                
            }
            
            pq.push({count,i});
            
            
            if(pq.size()>k){
                pq.pop();
            }
            
            count=0;
        }
        
        
        vector<int>res;
        
        
        while(pq.size()>0){
            
            
            int cur=pq.top().second;
            pq.pop();
            
            res.push_back(cur);
        }
        
        
        reverse(res.begin(),res.end());
        return res;
        
        
        
    }
};
