class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        //Sort the array for Better traversing in order...
        Arrays.sort(nums);

        int prev = nums[0] - k;
        int ans = 1;
        for(int i=1;i<nums.length;i++){
            //if adjacent no's are not same i.e., definitely a distinct no
            if(nums[i-1] != nums[i]){
                prev = Math.max(++prev,nums[i] - k);
                ans++;
            }else{
                if(nums[i]-k <= (prev+1) && nums[i]+k >= (prev+1)){
                    ans++;
                    prev++;
                }
            }
        }

        return ans;
    }
}