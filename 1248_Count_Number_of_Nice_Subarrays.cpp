class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prefix_sum = 0;
        unordered_map<int,int> map;//To store no of odd no appear in each index i...
        map[0] = 1;// prefix_sum[i]=k,then there is subarray from {o to i}
        int ans =0;//No of subarrays appeared...

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 !=0 )//if odd no..
                prefix_sum++;
            int x = prefix_sum - k;
            if(map.find(x) != map.end()){
                ans += map[x];
            }
            map[prefix_sum]++;//when index i is moved further..
        }

        return ans;
    }
};