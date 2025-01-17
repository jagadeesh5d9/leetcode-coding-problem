class Solution {
public:
//Global Declaration..
    vector<vector<int>>ans;
    vector<int>res;

    void bfs(vector<int> candidates, int target,int sum,int start){
        //base case..
        if(sum == target){
            ans.push_back(res);
            return;
        }
        if(sum > target) return ;

        for(int i=start;i<candidates.size();i++){
            res.push_back(candidates[i]);
            // sum += candidates[i];
            bfs(candidates,target,sum+candidates[i],i);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        bfs(candidates,target,0,0); 
        return ans;
    }
};