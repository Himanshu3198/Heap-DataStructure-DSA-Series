class Solution {
public:
    

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
    
        sort(trips.begin(),trips.end(),[&](vector<int>&a,vector<int>&b){
        
            return a[1]<b[1];
        });
        
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        
           int  curr_cap=0;
        
             for(int i=0;i<trips.size();i++){
               
                   int start=trips[i][1];
                   int end=trips[i][2];
                   int cap=trips[i][0];
             
               
               if(minHeap.size()>0){
                   
                   while(!minHeap.empty() and start>=minHeap.top().first){
                      auto [endded,index]=minHeap.top();                   
                      curr_cap-=trips[index][0];
                      minHeap.pop();
               }
               
               }
    
                   if((curr_cap+cap)<=capacity){
                       curr_cap+=cap;
                      
                       
                       minHeap.push({trips[i][2],i});
                       
                   }else if(curr_cap>capacity or (curr_cap+cap)>capacity){
                       return false;
                   }
                   
           }
         
          
         return true;
        
        

    }
};
