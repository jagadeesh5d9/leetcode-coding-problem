class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            int ans  = 0;
            int l=0,r=0;
            while(l<n){
                if(r-l+1<k){
                    if(colors[r%n]==colors[(r+1)%n]){//If no match,move to the next element..
                        l=r+1;
                    }
                    r=(r+1);
                }else{
                    ans++;
                    if(colors[r%n]==colors[(r+1)%n]){   //if No alternating on its right, move to that element, no need to check remaining...
                        l=(r+1);
                    }else
                        l++;
                        
                    r=(r+1);
                }
            }
            return ans;
        }
    };