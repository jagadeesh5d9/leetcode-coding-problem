class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        int l=0,r=0;//To maintain the window..
        int count=0;
        unordered_map<char,int> map;//store the character and frequency..

        while(r<n){
            if(r-l+1 < 3){
                map[s[r]]++;
                r++;
            }else{
                map[s[r]]++;
                if(map.size() == 3) //If unique values are inserted in map form the window with size 3..
                    count++;

                map[s[l]]--;
                if(map[s[l]] == 0)//remove the element at index l if frequency is "0"..
                    map.erase(s[l]);
                l++;
                r++;
            }
        }
        return count; //Return no of good substrings...
    }
};