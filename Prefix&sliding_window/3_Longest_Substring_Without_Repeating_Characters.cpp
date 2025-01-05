class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        if(n==0) return n;//If the length of the strign is 0 i.e, ""

        int l=0,r=0;
        int ans = INT_MIN;
        unordered_map<char,int>map;
        int temp =0;//For shrinking purpose..

        while(r<n){
            if(temp == 0)
                map[s[r]]++;

            if(map[s[r]] == 1){//if substring is valid..
                ans = max(ans,(r-l+1));
                temp =0;//if it is valid ,then temp =0 means we can add values to the map...
                r++;
            }else{//if not..
                temp = 1;//update the temp ,because in each itereation after updating the index 'l',map[s[r]] should not be added to the map,
                map[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};