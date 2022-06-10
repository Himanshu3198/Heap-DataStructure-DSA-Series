class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        
            unordered_map<string,int>mp;
            int maxi=0;
            for(int i=0;i<senders.size();i++){
                
                  string person=senders[i];
                  string msg=messages[i];
                  int cnt=0;
                  for(int i=0;i<msg.size();i++){
                      
                      if(msg[i]==' '){
                         mp[person]++;
                      }
                  }
                  mp[person]++;
                  maxi=max(maxi,mp[person]);
            }
        
            priority_queue<string,vector<string>>pq;
            for(auto it:mp){
                
                if(it.second==maxi) pq.push(it.first);
            }
            return pq.top();
            
    }
};
