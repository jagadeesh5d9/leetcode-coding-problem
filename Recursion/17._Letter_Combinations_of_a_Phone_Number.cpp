class Solution {
public:
//Keys and the values...
    unordered_map<char,string>map={
        {'1',"[]"},
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    string res = "";//store temparary string...
    vector<string>ans;

    void dfs(int i,int n,string digits){
        //Base case..
        if(i==n){
            ans.push_back(res);
            return ;
        }

        string temp = map[digits[i]];

        for(int j=0;j<temp.length();j++){
            res += temp[j];
            dfs(i+1,n,digits);//Recurrence...
            res.pop_back();//Backtracing..
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        //if digits.length() is 0;
        if (n==0){
            // ans.push_back(map['1']);
            return ans;
        }
        dfs(0,n,digits);
        return ans;
    }
};