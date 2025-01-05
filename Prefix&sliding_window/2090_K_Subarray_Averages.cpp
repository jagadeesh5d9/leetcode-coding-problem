class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        //Prefix sum for finding (r+k) sum
        vector<long long int> prefix_sum(n);
        prefix_sum[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }

        vector<int> ans;
        if(k==0) { //IF length is "0" then Each element return the same no. Because length becomes 1 (includes)
            for(int i:nums)
                ans.push_back(i);
            return ans;
            
                //OR
                // We can simply return the nums array...
        }

        int l=0,r=0;
        long long int sum=0;
        int div = (k*2)+1; // if that window available,then size becomes k*2+1 (i-k to i+k)
        while(r<n-k){ //Until last 'k' three digits..
            if(r-l+1 <= k){
                ans.push_back(-1);
                sum += nums[r];
                r++;
            }else{
                sum += nums[r]; //Sum from l to r indices...
                int temp = (sum + prefix_sum[r+k] - prefix_sum[r])/div;// sum of $sum and (r+1 to r+k)
                ans.push_back(temp);
                sum -= nums[l];
                r++;
                l++;
            }
        }
        //if right side does not have k elements....
        //Make them as -1
        while(r<n){
            ans.push_back(-1);
            r++;
        }
        return ans;
    }
};