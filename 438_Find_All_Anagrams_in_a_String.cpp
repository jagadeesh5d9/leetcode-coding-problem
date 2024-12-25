class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        vector<int> map(26,0);//to store the subarray characters...
        vector<int> pat(26,0);//vector which stores the pattern string in their respected index no 

        //Storing the string 'p'
        for(char x:p){
            pat[x-'a']++;
        }

        vector<int> ans;

        int l=0,r=0;
        while(r<n){
            if(r-l+1<k){//until window size matches ,store the string characters...
                map[s[r]-'a']++;
                r++;
            }else{
                map[s[r]-'a']++;
                if(map == pat)
                    ans.push_back(l);

                map[s[l]-'a']--;//remove the character at index 'l'
                l++;
                r++;
            }
        }
        return ans;
    }
};