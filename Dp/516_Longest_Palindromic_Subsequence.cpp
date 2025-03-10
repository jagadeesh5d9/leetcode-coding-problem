//Memoization...(two variable approach...)

class Solution {
    public:
        int helper(int i,int j, string &s,vector<vector<int>>&dp){
            //base case..
            if(i==j) return 1;
            if(i>j) return 0;
    
            if(dp[i][j]!=-1) return dp[i][j];
    
            if(s[i] == s[j]){ //if two characters are equal...
                dp[i][j] = 2+helper(i+1,j-1,s,dp);
                return dp[i][j];
            }
            // otherwise, two choices are there,
            // fix i, move j (or) fix j , move i
            dp[i][j] = max(helper(i,j-1,s,dp),helper(i+1,j,s,dp));
            return dp[i][j];
        }
    
        int longestPalindromeSubseq(string s) {
            int n = s.length();
            vector<vector<int>>dp(n,vector<int>(n,-1));
            return helper(0,n-1,s,dp);
        } 
    }; 

//Bottom Up approach....

class Solution {
    public:
        
        int longestPalindromeSubseq(string s) {
            int n = s.length();
            vector<vector<int>>dp(n,vector<int>(n,0));
            for(int l=1;l<=n;l++){ //Fill the array based on the length...
                for(int beg=0;beg<=n-l;beg++){
                    int end = beg+l-1;
                    if(beg==end){
                        dp[beg][end]=1;
                    }else if(beg+1==end){
                        if(s[beg]==s[end]){
                            dp[beg][end]=2;
                        }else{
                            dp[beg][end]=1;
                        }
                    }else{
                        if(s[beg]==s[end]){
                            dp[beg][end]=2+dp[beg+1][end-1];
                        }else{
                            dp[beg][end]=max(dp[beg][end-1],dp[beg+1][end]);
                        }
                    }
                }
            }
            return dp[0][n-1];
        } 
    }; 