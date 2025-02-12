class Solution {
    public:
    //For finding the total sum of the digits...
        int sum(int n){
            int res = 0;
            while(n>0){
                res += n%10;
                n/=10;
            }
            return res;
        }
    
        int maximumSum(vector<int>& nums) {
            unordered_map<int,vector<int>>map;
            for(int i:nums){
                int temp = sum(i);
                map[temp].push_back(i);//store the values in the map which have the same total digits sum...
            }

            int ans = -1;
            for(auto x:map){
                int size = x.second.size();
                if(size>2){//more than two are there in the vector then sorting is needed..
                    sort(x.second.begin(),x.second.end());
                    int temp = x.second[size-1]+x.second[size-2];
                    ans =  max(ans,temp);
                }else if(size == 2){//NO sorting is needed..
                    int temp = x.second[0]+x.second[1];
                    ans =  max(ans,temp);
                }
            }
            return ans;
        }
    };