class Solution {
public:

    void bfs(int start,int n,int k,vector<int>&res,vector<vector<int>>&ans){

        //Base case...
        if(res.size()==k ){
            ans.push_back(res);
            return ;
        }   

        for(int i=start;i<=n;i++){
            res.push_back(i);
            bfs(i+1,n,k,res,ans);//Recursive call..
            res.pop_back();//Backtracking..
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>res;
        vector<vector<int>>ans;

        bfs(1,n,k,res,ans);
        return ans;
    }
};