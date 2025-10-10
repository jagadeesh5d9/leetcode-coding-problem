//Solution with TC of O(n) using prefix sum...

class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length;
        int[] arr = new int[n];

        int ans = Integer.MIN_VALUE;
        for(int i=n-1;i>=0;i--){
            int temp = (i+k)<n ? arr[i+k] : 0;
            arr[i] = energy[i] + temp;
            ans = Math.max(ans,arr[i]);
        }

        return ans;
    }
}