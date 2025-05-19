class Solution {
public:
    string triangleType(vector<int>& nums) {
        int total = 0;
        for(int i:nums){
            total += i;
        }

        for(int i:nums){
            if(i>=(total-i))
                return "none";
        }
        unordered_map<int,int>map;
        for(int i:nums){
            map[i]++;
        }

        if(map.size()==1) return "equilateral";
        if(map.size()==2) return "isosceles";
        return "scalene";
    }
};