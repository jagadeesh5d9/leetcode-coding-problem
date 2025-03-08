class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n = blocks.size();
            vector<int>dp(n);
            dp[0] = blocks[0]=='B'?1:0;
    
            for(int i=1;i<n;i++){
                if(blocks[i]=='B'){
                    dp[i] = dp[i-1] + 1;
                }else{
                    dp[i] = dp[i-1];
                }
            }
    
            int ans = INT_MAX;
            int left = 0;
            while((left+k-1)<n){
                int end = left+k-1;
                if(left == 0){
                    ans = min(ans,k-dp[end]);
                }else{
                    ans = min(ans,k-(dp[end]-dp[left-1]));
                }
                left++;
            }
            return ans;
        }
    };