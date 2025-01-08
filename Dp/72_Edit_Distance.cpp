class Solution {
public:
    int dp[501][501];
    
    int helper(int i,int j,int n,int m,string A,string B){
        //Base case..
        if(i==n && j==m) 
            return 0;
        if(i==n)
            return (m-j);
        if(j==m)
            return (n-i);

        if(dp[i][j]!=-1) return dp[i][j];

        int ans =0;

        if(A[i]==B[j]){
            ans = helper(i+1,j+1,n,m,A,B);
        }else{

            ans = 1+min({helper(i+1,j,n,m,A,B),helper(i,j+1,n,m,A,B),helper(i+1,j+1,n,m,A,B)});
            dp[i][j]=ans;
        }
    return ans;
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        memset(dp,-1,sizeof(dp));
        return helper(0,0,n,m,word1,word2);
    }
};