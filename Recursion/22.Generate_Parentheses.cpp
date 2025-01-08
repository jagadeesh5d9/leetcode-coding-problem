class Solution {
public:
    void dfs(int open,int close,string &res,vector<string>&ans){
        //base case..
        if(open ==0 && close==0){
            ans.push_back(res);
            return;
        }

        //for adding open braces to the string ...
        if(open>0){
            res += '(';
            dfs(open-1,close,res,ans);
            res.pop_back();
        }
        //validation for adding close braces...
        if(close>open){
            res += ')';
            dfs(open,close-1,res,ans);
            res.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string res="";
        vector<string>ans;
        dfs(n,n,res,ans);
        return ans;
    }
};