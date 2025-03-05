class Solution {
    public:
    
        //finding the hamming distance...
        int ham(string a,string b){
            int count=0;
            for(int i=0;i<a.length();i++){
                if(a[i]!=b[i])
                    count++;
            }
            return count;
        }
    
        vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int n = words.size();
            vector<int>dp(n,1);//for storing the length of subsequence...
            vector<int>chain(n);//holding the previous element index to form chain 
            for(int i=0;i<n;i++){
                chain[i]=i;
            }
    
            int ans=dp[0],index=0;
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    //conditions..
                    if(words[i].length()==words[j].length() && groups[i]!=groups[j]){
                        int hd = ham(words[i],words[j]);
                        if(hd==1 && 1+dp[j]>dp[i]){
                            dp[i] = 1+dp[j];
                            chain[i]=j;
                        }
                    }
                }
                // finding max index ..
                if(ans<dp[i]){
                    ans = dp[i];
                    index = i;
                }
            }
            
            vector<string>res;
            while(dp[index]!=1){
                res.push_back(words[index]);
                index = chain[index];
            }
            res.push_back(words[index]);
            reverse(res.begin(),res.end());
            return res;
        }
    };