class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int> map;
        int ans =INT_MAX;//Initialize the ans as max_int(10^9)...

        //find the prefix sum array..
        vector<int> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix_sum[i] = prefix_sum[i-1]+nums[i];
        }

        //finding suffix sum and store it in hash table(unordered_map)..
        int suf_sum=0;
        for(int i=n-1;i>=0;i--){
            suf_sum += nums[i];
            map[suf_sum] = i;
        }

        //check for "x" in the hash table..
        if(map.find(x) != map.end()){
            ans = (n-map[x]);
        }

        for(int i=0;i<n;i++){
            int k = x-prefix_sum[i];
            if(k==0){//For prefix sum array...
                ans = min(ans, i+1);
            }else if(k>0){ // (x-prefix_sum[i]) > 0 means that we need to check for k in map
                if(map.find(k) != map.end() && i < map[k]){ //if (i<j) condition satisfies..
                    int len = (i+1) + (n- map[k]);
                    ans = min(ans,len);
                }
            }else{
                break; //if (k<0) no need to check further...
            }
        }

        if(ans == INT_MAX ) return -1; //if there is nothing matches "x"....
        return ans;
    }
};