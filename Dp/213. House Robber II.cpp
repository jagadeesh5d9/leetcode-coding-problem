//No dp , using two variables...
    class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 1) return nums[0];

            //Break the array into two linear arrays ....
            int t = nums[0];
            int nt = nums[1];
            if(n == 2) return max(t,nt);
            for(int i=2;i<=n-2;i++){
                // t = nt;
                int best = max(nums[i]+t, nt);
                // cout<<t<<","<<nt<<"-"<<best<<endl;
                t = max(t,nt);
                nt = best;
            }
            int res1 = max(t, nt);
            cout<< res1<<endl;
            //Second part of the array....
            t = nums[1];
            nt = nums[2];
            for(int i=3;i<=n-1;i++){
                // t = nt;
                int best = max(nums[i]+t, nt);
                t = max(t,nt);
                nt = best;
            }
            int res2 = max(t, nt);
            cout<<res2;

            return max(res1, res2);

        }
    };