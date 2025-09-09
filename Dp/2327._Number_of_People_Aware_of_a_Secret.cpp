//Memoization...
class Solution {
public:
int num = 1e9+7;//For make the values within the int range...

    long long helper(int day,int delay,int forget,int n,vector<long long>&dp){
        //base case..
        if(day>n) return 0;
        if(dp[day]!=-1) 
            return dp[day];

        long long ans  = 0;
        if(day>(n-forget)) ans++;//Days with remember the secreat...
        //Iterate the loop from (i+delay) to (i+forget-1)
        //Because these are said to be valid for counting....
        for(int i=(day+delay);i<(day+forget);i++){
            if(i>n) break;
            // if(i>(n-forget)) 
            //     ans++;
            ans = (ans+helper(i,delay,forget,n,dp))%num;//Recursion for the sub problems...
        }
        dp[day] = ans;
        return ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1,-1);//DP for storing the repeated values.....
        long long ans = helper(1,delay,forget,n,dp);
        return (ans%num);
    }
};