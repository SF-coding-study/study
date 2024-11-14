class Solution {
    public int solution(int n, int[][] computers) {
        boolean[] visited = new boolean[n];
        int networkCount = 0;
        
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                dfs(node, n, computers, visited);
                networkCount++;
            }
        }
        
        return networkCount;
    }
    
    private void dfs(int current, int n, int[][] computers, boolean[] visited) {
        visited[current] = true;
        
        for (int next = 0; next < n; next++) {
            if (!visited[next] && computers[current][next] == 1) {
                dfs(next, n, computers, visited);
            }
        }
    }
}