class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        int n = nums.length;
        // boolean[] ans = new boolean[n];
        List<Boolean> ans = new ArrayList<>();

        int temp = 0;
        int ind = 0;
        for(int i:nums){
            //(num + x) % k is as (nums%5 + x) % k
            temp = (temp *2 + i) % 5;//this is why we add " %5 "...
            System.out.println(temp);
            if(temp == 0) ans.add(true);
            else ans.add(false);

            ind++;
        }

        return ans;
    }
}