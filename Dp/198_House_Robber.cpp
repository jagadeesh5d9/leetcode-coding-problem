
//Solution 2:O(n) TC
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n==1)
                return nums[0];
            vector<int>dp(n);
            dp[0]=nums[0];
            dp[1]=nums[1];
            int ans = INT_MIN;
            for(int i=2;i<n;i++){
                ans = max(ans,dp[i-2]);
                dp[i] = ans+nums[i];
            }
            int res = INT_MIN;
            for(int i=0;i<n;i++){
                res = max(res,dp[i]);
            }
            return res;
        }
    };
    
// Solution 1:with O(n^2) TC...
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n==1)
                return nums[0];
            vector<int>dp(n);
            dp[0]=nums[0];
            dp[1]=nums[1];
            for(int i=2;i<n;i++){
                int ans = INT_MIN;
                for(int j=0;j<i-1;j++){
                    ans = max(ans,dp[j]);
                }
                dp[i] = ans+nums[i];
            }
            int res = INT_MIN;
            for(int i=0;i<n;i++){
                res = max(res,dp[i]);
            }
            return res;
        }
    };
