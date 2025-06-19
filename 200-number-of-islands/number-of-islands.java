class Solution {
    public void bfs(int rows,int cols,int[][] vis,char[][] grid){
        vis[rows][cols] =1;
        Queue<Pair> q = new LinkedList<Pair>();
        q.add(new Pair(rows,cols));
        int n = grid.length;
        int m = grid[0].length;

        int[] rowDirection = {-1, 0, 1, 0};  // up, right, down, left
        int[] colDirection = {0, 1, 0, -1};
        while (!q.isEmpty()) {
        Pair current = q.remove();
        int currentRow = current.first;
        int currentCol = current.second;

        // Check all 4 directions
        for (int i = 0; i < 4; i++) {
            int newRow = currentRow + rowDirection[i];
            int newCol = currentCol + colDirection[i];

            // Check if new cell is valid
            boolean inBounds = newRow >= 0 && newCol >= 0 && newRow < n && newCol < m;
            if (inBounds && vis[newRow][newCol] == 0 && grid[newRow][newCol] == '1') {
                vis[newRow][newCol] = 1;  // mark as visited
                q.add(new Pair(newRow, newCol));  // add to queue
            }
        }
        }
        
    }



    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int vis[][]= new int[n][m];
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 & grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;

    }
}
class Pair{
    int first;
    int second;
    public Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}