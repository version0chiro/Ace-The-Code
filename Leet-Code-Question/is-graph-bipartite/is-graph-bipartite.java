class Solution {
    int[] parent;
    public boolean isBipartite(int[][] graph) {
        int N = graph.length;
        parent = new int[N];
        for(int i = 0; i < N; i++)
            parent[i] = i;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < graph[i].length; j++) {
                if(find(i) == find(graph[i][j]))
                    return false;
                union(graph[i][0], graph[i][j]);
            }
        }
        
        return true;
    }
    
    private int find(int x) {
        while(x != parent[x])
            x = parent[x];  
        return x;
    }
    
    private void union(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        parent[parentY] = parentX;
    }
}