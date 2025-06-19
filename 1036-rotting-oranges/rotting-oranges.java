import java.util.*;

class Solution {
    class Pair {
        int row, col;

        Pair(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }

    public int orangesRotting(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        Queue<Pair> queue = new LinkedList<>();
        int fresh = 0;

        // Add initial rotten oranges to queue and count fresh ones
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new Pair(i, j));
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0; // No fresh orange to rot

        int minutes = 0;
        int[] dRow = {-1, 1, 0, 0}; // up, down
        int[] dCol = {0, 0, -1, 1}; // left, right

        // BFS to rot fresh oranges
        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean rotted = false;

            for (int i = 0; i < size; i++) {
                Pair p = queue.poll();
                for (int d = 0; d < 4; d++) {
                    int newRow = p.row + dRow[d];
                    int newCol = p.col + dCol[d];

                    if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        queue.add(new Pair(newRow, newCol));
                        fresh--;
                        rotted = true;
                    }
                }
            }

            if (rotted) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
}
