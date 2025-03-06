// Bottom up approach ...
class Solution {
    public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        // return helper(m-1,n-1,grid,dp,0);
        dp[0][0] = grid[0][0];
            for(int i=1;i<m;i++){
                dp[i][0] = dp[i-1][0]+grid[i][0];
            }
            for(int i=1;i<n;i++){
                dp[0][i] = dp[0][i-1]+grid[0][i];
            }
            
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    dp[i][j] = grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
                }
            }
            return dp[m-1][n-1];
        }
    };

//Memoization approach..

    //     int helper(int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp,int sum){
    //         //base case..
    //         if(m==0 && n==0)
    //             return grid[0][0]+sum;
    //         if(dp[m][n]!=-1) return dp[m][n];
            
    //         int up = INT_MAX;
    //         if(m>0)
    //             up = helper(m-1,n,grid,dp,sum+grid[m][n]);
    //         int down = INT_MAX;
    //         if(n>0)
    //             down = helper(m,n-1,grid,dp,sum+grid[m][n]);
    
    //         dp[m][n] = min(up,down);
    //         return dp[m][n];
    //     }