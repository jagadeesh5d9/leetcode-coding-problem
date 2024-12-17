class NumArray {
public:
    vector<int>pre_sum;

    NumArray(vector<int>& nums) {
        pre_sum.resize(nums.size());
        pre_sum[0]=nums[0];
        for(int i=1;i<nums.size();i++){
           int temp = nums[i] + pre_sum[i-1];
           pre_sum[i] = temp;
        }
    }
    
    int sumRange(int left, int right) {
        if (left ==0) return pre_sum[right];
        
        return (pre_sum[right]-pre_sum[left-1]);
    }
};