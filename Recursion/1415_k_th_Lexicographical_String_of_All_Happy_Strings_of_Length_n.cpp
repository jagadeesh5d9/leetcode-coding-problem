class Solution {
public:
    vector<string>ans;
    string res = "";
    string str = "abc";

    void bfs(int n , char prev){
        //Base case...
        if(res.length() == n){
            ans.push_back(res);
            return;
        }

        for(int i=0;i<str.length();i++){
            if(str[i] != prev){
                res += str[i];
                bfs(n,str[i]);
                res.pop_back();//Backtrack....
            }
        }
    }

    string getHappyString(int n, int k) {
        bfs(n,'/');
        if(k>ans.size())//there is no k th string...
            return "";
        return ans[k-1];// 0 based indexing....
    }
};