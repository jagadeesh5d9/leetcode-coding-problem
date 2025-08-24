class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=0,ans=0;
        int count=0;
        int temp = true;
        while(r<n){
            if(temp == true && nums[r]==0){
                count++;
            }

            if(count<=1){
                ans = max(ans,r-l+1);
                r++;
                temp = true;
            }else{
                if(nums[l]==0) 
                    count--;
                l++;
                temp = false;
            }
        }
        return ans-1;//we need to delete one elements from the array whether it is 1 or 0...
    }
};