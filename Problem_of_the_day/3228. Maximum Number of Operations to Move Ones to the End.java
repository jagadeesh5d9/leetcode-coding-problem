//Simple counting problem...

    //Just the logic...

    class Solution {
        public int maxOperations(String s) {
            int ans = 0;
            int count = 0;
            int temp = 0;
            for(int i=0;i<s.length();i++){
                if(s.charAt(i) == '1'){
                    temp = 1;
                    count++;
                } else{
                    if(temp == 0) continue;
                    ans += count;
                    temp = 0;
                }
            }
            return ans;
        }
    }