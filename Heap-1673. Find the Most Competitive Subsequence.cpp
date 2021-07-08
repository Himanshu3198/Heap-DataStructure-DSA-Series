1673. Find the Most Competitive Subsequence

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
           /*first find size of resultant vector  which can be done by  int rem=nums.size()-k;
           
     and push first element into the result vector now check if the current element is less than 
     
     last element present in the vector if yes then pop back element from the vector untill it become greater than 
     current element and keep in  mind that while poping  out the element from the vector the should not become zero of 
     current vector this can de done by rem variable it will not let the size become zero  this is all about while loop  
     after coming out from nums loop check if rem>0 if yes then simply  pop out the elements till rem become 0   */
         
        vector<int>res;
        
        int rem=nums.size()-k;
        
        for(auto it:nums){
            
            while(res.size() and rem and  it<res.back()){
                
                res.pop_back();
                rem--;
            }
            
            res.push_back(it);
        }
        
        while(rem--){
            
            res.pop_back();
            
        }
        return res;
 
    }
        
    
    
};
