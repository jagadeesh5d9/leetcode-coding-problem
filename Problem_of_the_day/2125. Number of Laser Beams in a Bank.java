class Solution {

    //Find the count of 1's in the string...
    static int findOnes(String str){
        int c = 0;
        for(int i=0;i<str.length();i++){
            if(str.charAt(i) == '1'){
                c++;
            }
        }
        return c;
    }

    public int numberOfBeams(String[] bank) {
        int r1 = findOnes(bank[0]);

        int ans = 0;
        for(int i=1;i<bank.length;i++){
            int r2 = findOnes(bank[i]);
            //If no security...
            if(r2 == 0) continue;
            ans += r1*r2;
            r1 = r2;
        }

        return ans;
    }
}