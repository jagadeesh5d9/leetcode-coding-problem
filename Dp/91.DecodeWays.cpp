class Solution {
public:
    //initialise the dp..
    int dp[101]={-1};

    int helper(int i,string s,int n){
        if(i==n) return 1;

        if(i>n || s[i] == '0') return 0;
        if(dp[i]!=-1) return dp[i];

        int ans = helper(i+1,s,n);//No need to check bound for this...

        if(i+1 < n){
            // Conversion of character to Number...
            int temp = (s[i]-'0')*10 + (s[i+1]-'0');
            ans += (temp>=10 && temp<=26) ? helper(i+2,s,n) : 0;
        }
        dp[i] = ans;
        return ans;
    }

    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        memset(dp,-1,sizeof(dp));//set to -1...
        return helper(0,s,s.length());
    }
};