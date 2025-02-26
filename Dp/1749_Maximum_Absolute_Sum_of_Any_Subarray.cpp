class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int min_sum = nums[0];
            int curr = nums[0];
            int max_sum = nums[0];
            int curr1 = nums[0];
            for(int i=1;i<nums.size();i++){
                //Min subarray sum...
                curr = min(curr+nums[i],nums[i]);
                min_sum = min(min_sum,curr);
                //Max subarray sum....
                curr1 = max(curr1+nums[i],nums[i]);
                max_sum = max(max_sum,curr1);
            }
            // return abs(min_sum);
            return max(max_sum,abs(min_sum));
        }
    };