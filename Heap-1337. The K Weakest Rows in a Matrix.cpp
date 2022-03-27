
//  time complexity O(n*m+ log(k))
//  space complexity O(k)

struct Matrix{
    
    int sum;
    int index;
    Matrix(int _s,int _idx){
        sum=_s;
        index=_idx;
    }
};

struct cmp{
    bool operator()(const Matrix &left,const Matrix &right)const{
        return left.sum==right.sum?left.index<right.index:left.sum<right.sum;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        
        priority_queue<Matrix,vector<Matrix>,cmp>pq;
        
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<mat[i].size();j++){
                
                sum+=mat[i][j];
            }
            pq.push({sum,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int>res(k--,0);
    
        while(!pq.empty()){
            
            res[k--]=pq.top().index;
            pq.pop();
        }
        return res;
    }
};
