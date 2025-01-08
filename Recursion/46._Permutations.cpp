class Solution {
public:

    void bfs(int i,int n,vector<int>nums,vector<int>&res,vector<vector<int>>&ans,vector<bool>& vis){
        if(i==n){//i is nothing but res.size() in each recursive call...
            ans.push_back(res);
            return;
        }

    //For every index we need to traverse through overall array ...
        for(int l=0;l<n;l++){
            if(!vis[l]){//If it is not visited...
                res.push_back(nums[l]);
                vis[l]=true;
                bfs(i+1,n,nums,res,ans,vis);//Recursive call for that respective array index...
                //Backtracking..
                res.pop_back();
                vis[l]=false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n,false);//visited array..
        vector<int>res;//store the permutations evaluated in each recursive call..
        vector<vector<int>>ans;//store all permutions..

        bfs(0,n,nums,res,ans,vis);
        return ans;
    }
};