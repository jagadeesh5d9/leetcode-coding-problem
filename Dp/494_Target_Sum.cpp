class Solution {
public:

    int dfs(int i,vector<int> &nums,int target,int sum,int n,unordered_map<string,int>&map){
        //Base case...
        if(i==n){
            return sum == target?1:0;
        }   

        string key = to_string(i)+','+to_string(sum);

        if(map.find(key)!=map.end()){
            return map[key];
        }

        map[key] = dfs(i+1,nums,target,sum+nums[i],n,map) + dfs(i+1,nums,target,sum-nums[i],n,map);
        
        return map[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // int ans = 0;
        int n = nums.size();
        unordered_map<string,int>map;

        return dfs(0,nums,target,0,n,map);
    }
};

//Note:
    // if use only use recursion ,we get the memory limit Exceed ....
