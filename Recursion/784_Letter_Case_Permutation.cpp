class Solution {
public:
    vector<string>ans;
    string res = "";

    void helper(string s,int n, int start){
        //Base case....
        if(res.length() == n){
            ans.push_back(res);
            return;
        }

        if(isupper(s[start])){//If char is uppercase letter..
            res += s[start];
            helper(s,n,start+1);
            res.pop_back();//Backtrack
            res += tolower(s[start]);//other choice for char...
            helper(s,n,start+1);
            res.pop_back();//Backtrack
        }else if(islower(s[start])){
            res += s[start];
            helper(s,n,start+1);
            res.pop_back();
            res += toupper(s[start]);
            helper(s,n,start+1);
            res.pop_back();
        }else{
            res += s[start];
            helper(s,n,start+1);
            res.pop_back();//Backtrack
        }
    }

    vector<string> letterCasePermutation(string s) {
        helper(s,s.length(),0);
        return ans;
    }
};