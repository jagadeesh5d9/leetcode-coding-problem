class Solution {
public:
    long long dp[301][301];//Taken based on the constrains...

    long helper(int i, int target, vector<int>&powers){
        //base case...
        if(target ==0) return 1;
        if(i>=powers.size() || target<0) return 0;

        if(dp[i][target]!=-1) return dp[i][target];

        long long ans = helper(i+1,target,powers) + helper(i+1,target-powers[i],powers);
        dp[i][target] = ans;
        return ans;
    }

    int numberOfWays(int n, int x) {
        //Find the power below "n"...
        vector<int>powers;
        for(int i=1;i<=n;i++){
            int temp = pow(i,x);
            if(temp>n) break;
            powers.push_back(temp);
        }

        memset(dp,-1,sizeof(dp));//set the dp to -1...

        long long ans = helper(0,n,powers);//ans can be more than 32-bit value...
        int f = 1e9+7;
        return int(ans%f);
    }
};