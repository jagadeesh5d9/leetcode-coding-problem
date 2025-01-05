class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l=0,r=0;
        int ans=INT_MAX,temp=0;

        int total=0;
        for(int i:cardPoints){
            total += i;
        }

        //If size of the subarray is n..
        if(n == k)
            return total;  
        
        int x = n-k;//check (n-k) window for min
        while(r<n){
            if(r-l+1 < x){
                temp += cardPoints[r];
                r++;
            }else{
                temp += cardPoints[r];
                ans = min(temp,ans);
                temp -= cardPoints[l];
                l++;
                r++;
            }
        }
        
        return (total-ans);//return the max..
    }
};