class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> map;//for maintaining the prefix sum and count..
        int sum = 0;//prefix sum
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

            if(sum == k) count++;//if prefix sum matches k

            int x = sum-k;
            if(map.find(x)!=map.end()){
                count+=map[x];//count of the prefix_sum [prefix_sum - k]
            }
             map[sum]++;//Add it to the map with count[initially 1]
        }
        return count;
    }
};