class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0,r=0;
        unordered_map<char,int>map;
        int ans=0;//intilalize the size of the longest subarray possible is 0...

        int max_No = 0;//Finding the max frequency in hash table...

        while(r<n){
            map[s[r]]++;//Growing the window..
            //Find the max freqncy of letter found....
            max_No = max(max_No,map[s[r]]);//To avoid for loop...

            //If it's not valid...
            //Shrink the window until its valid...
            while(((r-l+1) - max_No) > k){
                map[s[l]]--;
                //while window shrinking ,we need to update the frequency and max_No....  
                max_No = max(max_No,map[s[l]]);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};