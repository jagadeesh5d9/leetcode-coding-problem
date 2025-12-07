//Using DFS ..
    // Time complexity:- O(m * n) each element is traversed only one time...
    // Space complexity:- O(M * n)
    
    class Solution {
        void helper(int i,int j, boolean[][] vis, char[][] grid,int m, int n){
            //base case...
            if(i<0 || i>=m || j<0 || j>=n || (vis[i][j] == true) || grid[i][j] == '0') return ;

            vis[i][j] = true;
            helper(i+1,j,vis,grid,m,n);
            helper(i,j+1,vis,grid,m,n);
            helper(i,j-1,vis,grid,m,n);
            helper(i-1,j,vis,grid,m,n);
        }

        public int numIslands(char[][] grid) {
            int m = grid.length;
            int n = grid[0].length;

            //visited array...
            boolean[][] vis = new boolean[m][n];
            for(int i =0;i<m;i++){
                for(int j = 0;j<n;j++){
                    vis[i][j] = false;
                }
            }

            int count = 0;

            for(int i=0;i<m;i++){
                for(int j =0;j<n;j++){
                    if(grid[i][j] == '1' && vis[i][j] == false){
                        count++;
                        helper(i,j,vis,grid,m,n);
                    }
                }
            }
            return count;
        }
    }