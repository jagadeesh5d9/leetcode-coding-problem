class Solution {
    public:
        int maxSubarraySumCircular(vector<int>& nums) {
            int max_sum=nums[0];
            int min_sum=nums[0];
            int total = nums[0];
            int curr_min = nums[0];
            int curr_max = nums[0];
    
            for(int i=1;i<nums.size();i++){
                total += nums[i];
                //maxsum subarray...
                curr_max = max(curr_max+nums[i],nums[i]);
                max_sum = max(max_sum,curr_max);
                //minsum subarray...
                curr_min = min(curr_min+nums[i],nums[i]);
                min_sum = min(min_sum,curr_min);
            }
            
            //If all values are negative then total == min_sum ,then return max_sum....
            if(total == min_sum) return max_sum;
    
            return max(total-min_sum,max_sum);
        }
    };

    //Find the max sum using kadane's algorithm.. because max_sum may not be in the circular..
    //Find the min sum for finding circular "max_sum", 
        // max_sum = total-min_sum