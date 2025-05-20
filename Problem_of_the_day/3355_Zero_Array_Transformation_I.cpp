//Brute force approach  
    // Time complexity:O(n^2)

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long ps = 0;
        for(int i:nums){
            ps += i;
        }

        for(int i=0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            while(l<=r && l<n){
                if(nums[l]>0){
                    nums[l] = nums[l]-1;
                    ps--;
                }
                l++;
            }
        }
        return ps==0 ?  true:false;
    }
};

//Optimized solution : O(n) using diff array...
    class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            vector<int>v(n+1,0);
            v[0] = nums[0];
            for(int i=1;i<n;i++){
                v[i] = nums[i]-nums[i-1];
            }

            for(int i=0;i<queries.size();i++){
                int l = queries[i][0];
                int r = queries[i][1];
                v[l]--;
                v[r+1]++;
            }

            if(v[0]>0) return false;

            for(int i=1;i<n;i++){
                v[i] = v[i-1]+v[i];
                if(v[i]>0) return false;
            }
            return true;
        }
    };