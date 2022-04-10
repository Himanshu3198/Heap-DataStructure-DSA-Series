//  time complexity O(n)+Olog(n)
//  space complexity O(n)
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(auto it:nums){
            minHeap.push(it);
        }
        int ans=-1;
        int mod=1e9+7;
        while(minHeap.size()>0 and k>0){
            int currMin=minHeap.top();
            minHeap.pop();
            currMin++;
            minHeap.push(currMin);
            k--;
        }
        long long int res;
        while(!minHeap.empty()){
            
            int curr=minHeap.top();
            minHeap.pop();
            if(ans==-1){
                ans=curr;
                res=curr%mod;
            }else{
                res=(res*curr)%mod;
                res=res%(mod);
                ans=(int)res;
            }
        }
        return ans;
    }
};
