class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            //optimized way to find the prime no till right...

            vector<bool> isPrime(right + 1, true);
            isPrime[0] = isPrime[1] = false;
    
            for (int i = 2; i * i <= right; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= right; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
            //Find all prime no from the range left,right...
            vector<int> ans;
            for (int i = left; i <= right; i++) {
                if (isPrime[i]) {
                    ans.push_back(i);
                }
            }
    
            int diff = INT_MAX;
            //no more than 1 primes exist, then we can't determine min..
            vector<int>res(2);
            if(ans.size()<2){
                res[0]=-1;
                res[1]=-1;
            }
            for(int i=1;i<ans.size();i++){
                if(diff>ans[i]-ans[i-1]){
                    res[0]=ans[i-1];
                    res[1]=ans[i];
                    diff = ans[i]-ans[i-1];
                }
            }
            return res;
        }
    };