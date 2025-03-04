class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            vector<int>dp(n,1);//For storing the max length of subset possible at index i ...
            vector<int>chain(n);//To find the subset elements...
            sort(nums.begin(),nums.end());
            
            for(int i=0;i<n;i++){
                chain[i] = i;
            }
    
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                        dp[i] = 1+dp[j];
                        chain[i]=j;
                    }
                }
            }
            int ans=dp[0],index=0;
            for(int i=1;i<n;i++){
                if(ans<dp[i]){
                    ans = dp[i];
                    index = i;
                }
            }
            vector<int>res;
            while(index!=chain[index]){
                res.push_back(nums[index]);
                index = chain[index];
            }
            res.push_back(nums[index]);
            reverse(res.begin(),res.end());
            return res;
        }
    };