class Solution {
    public static int findCircleNum(int[][] isConnected) {
        int rows = isConnected.length;
        int cols = isConnected[0].length;
        int totalLength = rows + cols;
        boolean[] visited = new boolean[rows];
        int count =0;
        for(int i=0;i<rows;i++){
            if(visited[i]==false){
                count++;
                dfs(isConnected,visited,i);
            }
        }
        return count;
    }
    public static void dfs(int[][] matrix, boolean[] visited, int node) {
        visited[node] = true;
        System.out.print(node + " ");

        for (int i = 0; i < matrix.length; i++) {
            if (matrix[node][i] == 1 && !visited[i]) {
                dfs(matrix, visited, i);
            }
        }
    }
}