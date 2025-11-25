class Solution {
    public int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0) return -1;
        int count = 1;
        int no = 0;

        //only k no of remainders are exists...
        while(count<=k){
            // no and no%k both results the same remainder....
            no = (no*10 + 1) % k;

            if(no == 0) return count;
            
            count++;
        }
        return count;
    }
}