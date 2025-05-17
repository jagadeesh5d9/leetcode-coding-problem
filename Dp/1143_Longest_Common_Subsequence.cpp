// Note:
    // parameter which you passed to the helper function should be by referece,
    // otherwise it will give you "TLE"...
class Solution {
    public:
        int helper(int ind1,int ind2,string &text1, string &text2,vector<vector<int>>&dp){
            //base case...
            if(ind1 <0 || ind2<0)
                return 0;
            if(dp[ind1][ind2]!= -1) return dp[ind1][ind2];

            //If match
            if(text1[ind1] == text2[ind2]){
                int ans = 1+helper(ind1-1,ind2-1,text1,text2,dp);
                dp[ind1][ind2] = ans;
                return ans;
            }
            
            // if Not match
            int ans = max(helper(ind1-1,ind2,text1,text2,dp),helper(ind1,ind2-1,text1,text2,dp));
            dp[ind1][ind2] = ans;
            return ans;
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
            return helper(text1.length()-1,text2.length()-1,text1,text2,dp);
        }
    };

// Bottom Up approach..
class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int n1 = text1.size();
            int n2 = text2.size();
            vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
            for(int i=0;i<=n2;i++){
                dp[0][i]=0;
            }
            for(int i=0;i<=n1;i++){
                dp[i][0]=0;
            }
    
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){
                    if(text1[i-1]==text2[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                    }
                }
            }
            return dp[n1][n2];
        }
    };