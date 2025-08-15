class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        //Using the loop [TC:O(log n)]
            // while(n>1){
            //     if(n%4!=0) return false;
            //     n /= 4; 
            // }
        //using the logorithm formula...
        double ans = log(n)/log(4);
        return floor(ans) == ans;//check ans whether int or double
    }
};