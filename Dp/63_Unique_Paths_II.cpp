class Solution {
    public:
        int helper(int m,int n,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
            //base case..
            if((m==0 && n==0) && obstacleGrid[m][n]!=1) return 1;
            if(obstacleGrid[m][n]==1) return 0;
            if(dp[m][n]!=-1) return dp[m][n];
    
            int up=0;
            if(m>0)
                up = helper(m-1,n,dp,obstacleGrid);
            int down =0;
            if(n>0)
                down = helper(m,n-1,dp,obstacleGrid);
            dp[m][n] = up+down;
            return dp[m][n];
        }
    
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>>dp(m,vector<int>(n,-1));
            return helper(m-1,n-1,dp,obstacleGrid);
        }
    };


//Bottom up approach..
class Solution {
    public:
        
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            if(obstacleGrid[0][0]==1) return 0;
    
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>>dp(m,vector<int>(n));
            int temp =0;
            for(int i=0;i<m;i++){
                if(obstacleGrid[i][0]!=1 && temp==0){
                    dp[i][0] = 1;
                }else{
                    dp[i][0] = 0;
                    temp = 1;
                }
            }
            temp =0;
            for(int i=0;i<n;i++){
                if(obstacleGrid[0][i]!=1 && temp==0){
                    dp[0][i] = 1;
                }else{
                    dp[0][i] = 0;
                    temp = 1;
                }
            }
    
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(obstacleGrid[i][j]!=1){
                        dp[i][j] = dp[i-1][j]+dp[i][j-1];
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };