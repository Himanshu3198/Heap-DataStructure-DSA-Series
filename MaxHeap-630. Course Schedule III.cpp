
//  t.c O(n*n(logn))
//  s.c O(n)
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),[&](const vector<int>a,const vector<int> b){
            return a[1]<b[1];
        });
        // for(auto it:courses) cout<<it[0]<< " "<<it[1]<<"\n";
        priority_queue<int,vector<int>>pq;
        int days=0;
        int n=courses.size();
        for(int i=0;i<n;i++){
            
                int duration=courses[i][0],lastDay=courses[i][1];
                days+=duration;
                pq.push(duration);
                if(days>lastDay){
                    days-=pq.top();
                    pq.pop();
                }
        }
        return pq.size();
    }
};
