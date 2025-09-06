class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans  = 0;
        for(auto query:queries){
            //Given range...
            //Take the values as long long, because return type is "long long"
            long long s = query[0];
            long long e = query[1];
            //4's range (4^0,4^1)
            //Based on the 4^i range , we can compute the operations required...
            long long p = 1;
            long long c = 1;

            //Finding Overlapping area for [s,e] && [p,c]
            long long op = 0;
            for(long long i=1;i<17;i++){
                if(p>e) break;
                c = c*4LL;//set 4^i  range..
                long long l = max(p,s);
                long long r = min(c-1,e);
                if(r>=l){
                    op += (r-l+1)*i;//i is the no of operations required to reduce the given no to be zero...
                }
                p = c;//update the 4^i range...
            }
            ans += (op+1)/2;//we can take 2 at a time...[we can divide 2 integers at a time with 4...]
        }
        return ans;
    }
};