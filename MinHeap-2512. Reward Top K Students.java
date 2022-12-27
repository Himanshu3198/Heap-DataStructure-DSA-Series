class studentScore{
    int points;
    int id;
       studentScore(int p,int i){
        points=p;
        id=i;
    }
}
class Solution {
    public List<Integer> topStudents(String[] positive_feedback, String[] negative_feedback, String[] report, int[] student_id, int k) {
     
        
         Set<String>posi=Arrays.stream(positive_feedback).collect(Collectors.toSet());
         Set<String>negi=Arrays.stream(negative_feedback).collect(Collectors.toSet());
         PriorityQueue<studentScore>minHeap=new PriorityQueue<>((a,b)->a.points==b.points?b.id-a.id:a.points-b.points);
         for(int i=0;i<report.length;i++){
             String []word=report[i].split(" ");
             int point=0;
             for(String s:word){
                 if(posi.contains(s)) point+=3;
                 else if(negi.contains(s)) point-=1;
             }
             minHeap.add(new studentScore(point,student_id[i]));
             if(minHeap.size()>k) minHeap.poll();
         }
         List<Integer>res=new ArrayList<>();
        while(!minHeap.isEmpty()){
            res.add(minHeap.poll().id);
        }
        Collections.reverse(res);
        return res;
    }
}
