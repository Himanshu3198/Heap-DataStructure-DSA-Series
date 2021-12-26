//  Time complexity N*log(K) 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
     
               int n=points.size();
              vector<vector<int>>res;
          
        priority_queue <pair<double,int> >maxHeap;
        
        
        for(int i={};i<n;i++){
            
            double dist= sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
           
            
            maxHeap.push({dist,i});
              if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        
        
        while(!maxHeap.empty() and k--){
            auto [_,idx]=maxHeap.top(); maxHeap.pop();
            
             res.push_back(points[idx]);
               
        }
        
        return res;
            
    }
};
