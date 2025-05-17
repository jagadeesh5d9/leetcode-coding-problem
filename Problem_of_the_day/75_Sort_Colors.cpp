class Solution {
public:

//Optimal solution using the 3-pointer approach...

    void sortColors(vector<int>& nums) {
        int l=0,m=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }else if(nums[m] == 1){
                m++;
            }else{
                swap(nums[h],nums[m]);
                h--;
            }
        }
    }
    
    //Solution using the hashmap...
    
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>map; //Optional.. we can also do without using this hashmap..

       for(int i:nums){
        map[i]++;
       }
       int zero = map[0];
       int one = map[1];
       int two = map[2];

       for(int i=0;i<nums.size();i++){
        if(zero!=0){
            nums[i] = 0;
            zero--;
        }
        else if(one!=0){
            nums[i] = 1;
            one--;
        }
        else if(two!=0){
            nums[i] = 2;
            two--;
        }
       }
    }
};