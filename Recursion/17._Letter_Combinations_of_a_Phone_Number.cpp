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

Data look up:
	automatically sets the value to the fields
	db_u_priority.LIST - data loop up table.
	Configure choice - add the new choice for the given field.

	Custom Data lookUp setUp:
		1:create custom fields
		2:configuration values - "configure dictionary"
		3:data loopUp Rule table creation:
			it should extend the table called - "d_match"