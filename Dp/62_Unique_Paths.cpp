class Solution {
    public:
        int helper(int m,int n,vector<vector<int>>&dp){
            //base case...
            if((m==0 && n==0)) return 1;
            if(m==0 || n==0) return 1;
    
            if(dp[m][n]!=-1) return dp[m][n];
    
            int up=0;
            if(m>0)
            up = helper(m-1,n,dp);
            int down = 0;
            if(n>0)
            down = helper(m,n-1,dp);
    
            dp[m][n] = up+down;
            return dp[m][n];
        }
    
        int uniquePaths(int m, int n) {
            vector<vector<int>>dp(m,vector<int>(n,-1));
            return helper(m-1,n-1,dp);
        }
    };


    //Bottom up approach..
    class Solution {
        public:
            
            int uniquePaths(int m, int n) {
                vector<vector<int>>dp(m,vector<int>(n));
                
                for(int i=0;i<m;i++){
                    dp[i][0] = 1;
                }
                for(int i=0;i<n;i++){
                    dp[0][i] = 1;
                }
        
                for(int i=1;i<m;i++){
                    for(int j=1;j<n;j++){
                        dp[i][j] = dp[i-1][j]+dp[i][j-1];
                    }
                }
                return dp[m-1][n-1];
            }
        };