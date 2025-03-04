class Solution {
    public:
        int helper(int index,vector<int>&dp,vector<int>&nums){
            //Base case..
            if(index==nums.size()-1) return 0;
            //if index goes beyond "n"
            if(index>nums.size()-1) return INT_MAX;
    
            if(dp[index]!=-1) return dp[index];
    
            int ans =INT_MAX;
            for(int i=index+1;i<=(index+nums[index]);i++){
                // ans = min(ans,1+helper(i,dp,nums));
                int jump = helper(i,dp,nums);
                if(jump != INT_MAX){ //For avoiding overflow...
                    ans = min(ans,1+jump);
                }
            }
            dp[index] = ans;
            return dp[index];
        }
    
        int jump(vector<int>& nums) {
            int n = nums.size();
            vector<int>dp(n,-1);
            return helper(0,dp,nums);
        }
    };