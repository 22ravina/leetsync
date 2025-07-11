class Pair{
    int first;
    int second;
    public Pair(int first,int second){
        this.first = first;
        this.second = second;
    }
}
class Solution {
    public int numEnclaves(int[][] grid) {
        Queue<Pair> q = new LinkedList<Pair>();
        int n = grid.length;
        int m = grid[0].length;
        int vis[][] = new int[n][m];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0|| i==n-1|| j==m-1){
                    if(grid[i][j]==1){
                        q.add(new Pair(i,j));
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delRows[] = {-1,0,+1,0};
        int delCols[] = {0,+1,0,-1};
        while(!q.isEmpty()){
            int rows = q.peek().first;//0
            int cols = q.peek().second;//3
            q.remove();
            for(int i=0;i<4;i++){
                int nrow = rows + delRows[i];
                int ncol = cols + delCols[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol <m &&
                vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.add(new Pair(nrow,ncol));
                    vis[nrow][ncol]=1;
                }
            }


        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 & vis[i][j]==0){
                    count++;

                }
            }
        }
        return count;
    }
}