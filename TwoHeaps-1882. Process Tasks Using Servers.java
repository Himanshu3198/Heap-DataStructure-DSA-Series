import java.util.*;

class Worker implements Comparable<Worker> {
    int wt;
    int idx;

    public Worker(int wt, int idx) {
        this.wt = wt;
        this.idx = idx;
    }

    @Override
    public int compareTo(Worker other) {
        if (this.wt == other.wt) {
            return Integer.compare(this.idx, other.idx);
        }
        return Integer.compare(this.wt, other.wt);
    }
}

class Available {
    int wt;
    int finishTime;
    int idx;

    public Available(int wt, int finishTime, int idx) {
        this.wt = wt;
        this.finishTime = finishTime;
        this.idx = idx;
    }
}

class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {

        int n = tasks.length;

        PriorityQueue<Worker> available = new PriorityQueue<>();
        PriorityQueue<Available> busy =
                new PriorityQueue<>((a, b) -> Integer.compare(a.finishTime, b.finishTime));

        for (int i = 0; i < servers.length; i++) {
            available.offer(new Worker(servers[i], i));
        }

        int[] res = new int[n];
        long timeStamp = 0;

        for (int i = 0; i < n; i++) {

            timeStamp = Math.max(timeStamp, i);

            // release completed servers
            while (!busy.isEmpty() && busy.peek().finishTime <= timeStamp) {
                Available avail = busy.poll();
                available.offer(new Worker(avail.wt, avail.idx));
            }

            // if no server available, fast forward time
            if (available.isEmpty()) {
                timeStamp = busy.peek().finishTime;

                while (!busy.isEmpty() && busy.peek().finishTime <= timeStamp) {
                    Available avail = busy.poll();
                    available.offer(new Worker(avail.wt, avail.idx));
                }
            }

            Worker currWorker = available.poll();
            res[i] = currWorker.idx;

            busy.offer(new Available(
                    currWorker.wt,
                    (int)(timeStamp + tasks[i]),
                    currWorker.idx
            ));
        }

        return res;
    }
}
