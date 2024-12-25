class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();

        int l=0,r=0;
        set<vector<char>> set;//To avoid duplicates...
        vector<char>v;
        
        //Find the all substrings that has length 'k' 
        while(r<n){
            if(r-l+1<k){
               v.push_back(s[r]);
               r++;
            }else{
                v.push_back(s[r]);
                set.insert(v);
                v.erase(v.begin());//Remove the l index character...
                //Update the starting and ending pointer of the window...
                l++;
                r++;
            }
        }
        
        //No of possible combination of "k" is  2^k or 1<<k... 
        if(set.size() == pow(2,k)) return true;//if all possible are appear in the set...
        return false;
    }
};