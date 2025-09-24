import java.util.*;

class Comp implements Comparable<Comp> {
    final int taskId;
    final int userId;
    final int priority;

    public Comp(int taskId, int userId, int priority) {
        this.taskId = taskId;
        this.userId = userId;
        this.priority = priority;
    }

    @Override
    public int compareTo(Comp other) {
        // Higher priority first
        if (this.priority != other.priority)
            return Integer.compare(other.priority, this.priority);
        // Tie-breaker: higher taskId first
        return Integer.compare(other.taskId, this.taskId);
    }
}

class TaskManager {
    private final PriorityQueue<Comp> pq;
    private final Map<Integer, Comp> taskMap; // taskId -> latest Comp

    public TaskManager(List<List<Integer>> tasks) {
        pq = new PriorityQueue<>();
        taskMap = new HashMap<>();
        if (tasks != null) {
            for (List<Integer> t : tasks) {
                if (t == null || t.size() < 3) continue;
                int userId = t.get(0), taskId = t.get(1), priority = t.get(2);
                add(userId, taskId, priority);
            }
        }
    }

    public void add(int userId, int taskId, int priority) {
        Comp c = new Comp(taskId, userId, priority);
        pq.add(c);
        taskMap.put(taskId, c);
    }

    public void edit(int taskId, int newPriority) {
        if (!taskMap.containsKey(taskId)) return;
        Comp old = taskMap.get(taskId);
        Comp updated = new Comp(taskId, old.userId, newPriority);
        pq.add(updated);           // add new updated task
        taskMap.put(taskId, updated); // map points to latest task
    }

    public void rmv(int taskId) {
        taskMap.remove(taskId); // lazy remove
    }

    public int execTop() {
        while (!pq.isEmpty()) {
            Comp top = pq.poll();
            // skip removed or outdated entries
            if (!taskMap.containsKey(top.taskId)) continue;
            if (taskMap.get(top.taskId) != top) continue;
            taskMap.remove(top.taskId);
            return top.userId;
        }
        return -1;
    }
}
