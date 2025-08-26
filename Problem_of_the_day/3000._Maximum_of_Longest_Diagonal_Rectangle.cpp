class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        double dia = 0;
        for(auto &dim:dimensions){
            int l = dim[0];
            int w = dim[1];
            double temp = sqrt((l*l) + (w*w));
            if(temp > dia){
                dia = temp;
                ans = l*w;
            }else if(temp == dia){
                ans =  max(ans,l*w);
            }
        }
        return ans;
    }
};