class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        unordered_map<int,int> map;

        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = ((sum%k)+k)%k;//Modulo division 
            // for negative no's not making the remainder as negavite
            
            if(rem==0) count++;//Without initialize the map as map[0]=1;
            if(map.find(rem) != map.end()){
                count+=map[rem];
            }
            map[rem]++;
        }
        return count;
    }
};