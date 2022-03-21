//  time complexity O(Log(n))
//  space complexity o(n)
class MedianFinder {
     priority_queue<int>maxHeap;
     priority_queue<int,vector<int>,greater<int>>minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size()==0 or maxHeap.top()>=num){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }
        balance();
    }
    
    double findMedian() {
        
        if(maxHeap.size()>minHeap.size()){
            double x=maxHeap.top();
            return x;
        }else if(minHeap.size()>maxHeap.size()){
            double x=minHeap.top();
            return x;
        }else{
                 double x=maxHeap.top();
                 double y=minHeap.top();
                 double ans=(x+y)/2.0;
                 return  ans;
        }
    }
      void balance(){
         
         if(maxHeap.size()>minHeap.size()+1){
               minHeap.push(maxHeap.top());
               maxHeap.pop();
         }else if(minHeap.size()>maxHeap.size()+1){
                
                   maxHeap.push(minHeap.top());
                   minHeap.pop();  
         }
     }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
