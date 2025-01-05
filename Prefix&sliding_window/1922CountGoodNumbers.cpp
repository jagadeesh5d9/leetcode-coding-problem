class Solution {
public:
    long long helper(int x,long long n){
        if(n==0){
            return 1;
        }

        long long ans = helper(x,n/2);
        ans = (ans*ans)%(1000000007);//10^9+7 is nothing but the module which is given...

        if(n%2 != 0){//if no is odd...
            ans = ((ans)*(x%(1000000007))) % (1000000007);
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long temp = helper(5,(n/2)+(n%2!=0));//Because of long value of n [constrain]
        long long temp1 =  helper(4,n/2);

        //without module we cant return int value because it cause a long long...
        int res = (temp*temp1)%(1000000007);
        
        return res;
    }
};