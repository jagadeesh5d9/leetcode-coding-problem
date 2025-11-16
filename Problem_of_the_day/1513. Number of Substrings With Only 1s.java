// Type conversion problem...

class Solution {
    public int numSub(String s) {
        long ans = 0;
        long c = 0;
        long mod = 1000000000 + 7;

        for(int i = 0;i<s.length();i++){
            if(s.charAt(i) == '1'){
                c++;
            }else{
                if(c == 0) continue;
                ans = (ans + (c*(c+1)) / 2) % mod;
                // System.out.println(ans+":-"+i);
                c = 0;
            }
        }

        // if(c == 0) return ans;
        ans = (ans + (c*(c+1)) / 2) % mod;        
        return (int)ans;
    }
}