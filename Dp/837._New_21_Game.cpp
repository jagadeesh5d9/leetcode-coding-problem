class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        //k==0 already stoped so return 1
        // "n>= k+maxPts" => max val it can reach is k+maxPts-1, so that return 1 if condition is statisfied...
        if(k==0 || n>= k+maxPts) return 1;

        vector<double>dp(n+1,0);
        dp[0]=1;
        double temp = 1;
        for(int i=1;i<=n;i++){
            dp[i] = temp/maxPts;//Probability of i
            //until k-1 we add the probbilities..
            //prob[n] = prob[k-1]+prob[k-2]+....+prob[n-maxPts]
            if(i<k){
                temp += dp[i];
            }
            //Exclude the val from the front 
            // cause range is from [k-1,i-maxPts] at i th point..
            if(i>=maxPts){
                temp -= dp[i-maxPts];
            }
        }
        //Add prob. from n to k [n or fewer...]
        double ans = 0;
        for(int i=k;i<=n;i++){
            ans += dp[i];
        }
        return ans;
    }
};