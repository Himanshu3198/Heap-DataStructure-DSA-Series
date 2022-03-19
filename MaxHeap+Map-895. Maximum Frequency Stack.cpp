
 struct Stack{
         
    
      int count;
      int val;
      int pos;
      Stack(int _c,int _v,int _p){
          count=_c;
          val=_v;
          pos=_p;
      }
     
        
    };
 struct cmp{
   bool operator ()  (const Stack &left,const Stack &right)const{
          
          return left.count==right.count?left.pos<right.pos:left.count<right.count;
         }
      };
class FreqStack {
public:
     
       priority_queue<Stack,vector<Stack>,cmp>pq;
       unordered_map<int,int>freq;
       int position=0;
    
    FreqStack() {
    }
    
    
    void push(int val) {
        
        freq[val]++;
        position++;
        pq.push(Stack(freq[val],val,position));
        
    }
    
    int pop() {
        
        int result=pq.top().val;
         pq.pop();
        
        
        
        freq[result]--;
        if(freq[result]<0){
            freq.erase(result);
        }
        
        return result;
          
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
