class Solution {
    public int minCost(String colors, int[] neededTime) {
        int ans = 0;
        int minVal = Integer.MAX_VALUE;
        int maxVal = Integer.MIN_VALUE;
        int start = 1;

        for(int i=0;i<colors.length()-1;i++){
            if(colors.charAt(i) == colors.charAt(i+1)){
                if(start == 1){
                    minVal = Math.min(neededTime[i],neededTime[i+1]);
                    maxVal = Math.max(neededTime[i],neededTime[i+1]);
                    ans += minVal;
                    start = 0;
                }else{
                    minVal = Math.min(maxVal, neededTime[i+1]);
                    maxVal = Math.max(maxVal, neededTime[i+1]);
                    ans += minVal;
                }
            }else{
                start = 1;
            }
            // System.out.println(i+"-ans: -:"+ans+"-:"+ minVal +","+ maxVal);
        }
        return ans;
    }
}