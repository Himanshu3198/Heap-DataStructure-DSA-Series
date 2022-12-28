class Solution {
    public int minStoneSum(int[] piles, int k) {
        
        PriorityQueue<Integer>maxHeap=new PriorityQueue<>((a,b)->b-a);
        for(int i:piles)
            maxHeap.add(i);
        while(k>0 && !maxHeap.isEmpty()){
            int x=maxHeap.poll();
            if(x%2==1)x=x/2+1;
            else x=x/2;
            maxHeap.add(x);
            k--;
        }
        int res=0;
        while(!maxHeap.isEmpty()) res+=maxHeap.poll();
        return res;
    }
}
