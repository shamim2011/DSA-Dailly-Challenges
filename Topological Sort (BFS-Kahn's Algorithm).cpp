import java.util.*;

class Solution {
    // Function to return a list containing vertices in Topological order.
    public List<Integer> topoSort(int N, List<List<Integer>> adj) {
        Queue<Integer> queue = new LinkedList<>();
        int[] indegree = new int[N];

        // Step 1: Compute in-degree of each node
        for (int u = 0; u < N; u++) {
            for (int v : adj.get(u)) {
                indegree[v]++;
            }
        }

        // Step 2: Add nodes with in-degree 0 to the queue
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
            }
        }

        // Step 3: Process nodes in the queue (BFS)
        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            int u = queue.poll();
            result.add(u); // Add to topological order

            for (int v : adj.get(u)) {
                indegree[v]--; // Reduce in-degree

                if (indegree[v] == 0) { // If in-degree becomes 0, add to queue
                    queue.add(v);
                }
            }
        }

        return result;
    }
}
