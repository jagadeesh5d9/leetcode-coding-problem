class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int ans = 0 ;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                sum -= 1;
            }else{
                sum += 1;
            }

            if(sum == 0) {
                ans = i+1;
            }
            else if(map.find(sum) == map.end()){
                    map[sum] = i;
                }
            else{
                    ans = max(ans,i-map[sum]);
                }
        }
         return ans;
    }
};