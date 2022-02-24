//  time complexity O(n)+O(nlog(n))
//  time complexity O(n)+O(n)
class Solution {
public:
    string repeatLimitedString(string s, int k) {
        
        
         map<char,int>mp;
        
        
        for(char &c:s){
            mp[c]++;
        }
        
        priority_queue<pair<char,int>,vector<pair<char,int>>>pq;
        
        
        for(auto it:mp){
            
            pq.push({it.first,it.second});
        }
        
        string res="";
        
        while(!pq.empty()){
            
              auto [c,n]=pq.top(); pq.pop();
            if(n<=k){
                
                res+=(string(n,c));
            }else{
                   int minRemove=min(k,n);
                   res+=(string(minRemove,c));
                         n-=minRemove;
                         
                         while(n>0 and !pq.empty()){
                             
                              auto  [c2,n2]=pq.top();
                            pq.pop();
                             
                             res+=(string(1,c2));
                             if(n2-1>0)
                              pq.push({c2,n2-1});
                             
                               minRemove=min(k,n);
                             res+=(string(minRemove,c));
                                   n-=minRemove;
            
                        }
                                   
             }
                
                   }
                                   
                        return res;                  
                }
};
