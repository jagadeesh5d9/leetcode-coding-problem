// Bottom up approach...
class Solution {
    public:
        string longestPalindrome(string s) {
            vector<vector<bool>>dp(s.length(),vector<bool>(s.length(),false));
            int st=0,e=0;
            for(int len = 1;len<=s.length();len++){
                for(int beg=0;beg<=s.length()-len;beg++){
                    int end = beg+len-1;
                    if(beg==end){
                        dp[beg][end]=true;
                    }else if(beg+1==end){
                        if(s[beg]==s[end]){
                            dp[beg][end]=true;
                            st=beg;
                            e=end;
                        }else{
                            dp[beg][end]=false;
                        }
                    }else{
                        if(s[beg]==s[end]){
                            dp[beg][end]=dp[beg+1][end-1];
                            if(dp[beg][end]==true){
                                st=beg;
                                e=end;
                            }
                        }else{
                            dp[beg][end]=false;
                        }
                    }
                }
            }
            string temp = "";
            for(int beg=st;beg<=e;beg++){
                temp += s[beg];
            }
            return temp;
        }
    };