class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
    
            if(n==1){
                int res = matrix[0][0];
                for(int i=1;i<n;i++){
                    res = min(res,matrix[0][i]);
                }
                return res;
            }
    
            vector<vector<int>>dp(n,vector<int>(n));
            for(int i=0;i<n;i++){
                dp[0][i] = matrix[0][i];
            }
    
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    if(j==0){
                        dp[i][j] = matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                    }else if(j==n-1){
                        dp[i][j] = matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                    }else{
                        dp[i][j] = matrix[i][j]+min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
                        // int res = min(dp[i-1][j-1],dp[i-1][j]);
                        // res = min(res,dp[i+1][j+1]);
                        // dp[i][j] = res;
                    }
                }
            }
            int ans = INT_MAX;
            for(int i=0;i<n;i++){
                ans = min(ans,dp[n-1][i]);
            }
            return ans;
        }
    };