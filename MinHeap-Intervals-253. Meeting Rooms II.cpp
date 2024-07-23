class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b){
       if(a[0]!=b[0]) return a[0]<b[0];
       return a[1]<b[1];
   }
   struct Comp {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[0] == b[0]) {
            return a[1] > b[1]; // Min heap based on the second element if the first elements are equal
        }
        return a[0] > b[0]; // Min heap based on the first element
     }
   };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        // for(auto it:intervals) cout<<it[0]<<" "<<it[1]<<"\n";
        priority_queue<vector<int>,vector<vector<int>>,Comp>minHeap;
        queue<vector<int>>refactor;
        for(auto itr:intervals){
             while(!minHeap.empty()){
                   vector<int>curr = minHeap.top();
                   minHeap.pop();
                   if(itr[0]>= curr[0] && itr[0]<curr[1]){
                      refactor.push(curr);
                   }   
                   else break;               
              }
              while(!refactor.empty()){
                  vector<int>temp = refactor.front();
                  refactor.pop();
                  minHeap.push(temp);
              }
              minHeap.push(itr);  
        }
        return minHeap.size();
          
    }
};
