//Simple recursive appraoch without using dp...

    class Solution {
        int ans = 0;

        void helper(int i,int[][] freq,int m, int n, String[] strs,ArrayList<Integer> sets){
            if(i> strs.length) return;

            if(!sets.isEmpty()){
                int one=0; 
                int zero=0;
                for(int p:sets){
                    zero += freq[p][0];
                    one += freq[p][1];
                }
                if(zero >m || one>n) return;
                for(int p:sets)
                    System.out.print(p+",");
                System.out.println("->"+ zero +","+ one);
                ans = Math.max(ans,sets.size());
            }

            sets.add(i);
            helper(i+1,freq,m,n,strs,sets);
            sets.remove(sets.size()-1);
            helper(i+1,freq,m,n,strs,sets);

        }

        public int findMaxForm(String[] strs, int m, int n) {
            int[][] freq = new int[strs.length][2];

            for(int i=0;i<strs.length;i++){
                int one = 0;
                int zero = 0;
                String temp = strs[i];
                for(int j=0;j<temp.length();j++){
                    if(temp.charAt(j) == '0') zero++;
                    else one++;
                }
                freq[i][0] = zero;
                freq[i][1] = one;
            }
            ArrayList<Integer> sets = new ArrayList<>();
            helper(0,freq,m,n,strs,sets);
            return ans;
        }
    }

//solution with DP...
    // pattern - 0/1 knapsack...

    class Solution {

        int helper(int i,int[][] freq,int m, int n, String[] strs,int[][][] dp){
            //base case...
            if(i == strs.length) return 0;

            if(dp[i][m][n]!=0) return dp[i][m][n];

            // Skip 
            int nt = helper(i+1,freq,m,n,strs,dp);

            int zero = freq[i][0]; 
            int one = freq[i][1]; 
            
            //take on valid condition...
            int take = 0;
            if(zero <= m && one<=n){
                take = 1+helper(i+1,freq,m-freq[i][0],n-freq[i][1],strs,dp);
            }

            int ans = Math.max(nt,take);
            dp[i][m][n] = ans;
            return ans;

        }

        public int findMaxForm(String[] strs, int m, int n) {
            int[][] freq = new int[strs.length][2];

            for(int i=0;i<strs.length;i++){
                int one = 0;
                int zero = 0;
                String temp = strs[i];
                for(int j=0;j<temp.length();j++){
                    if(temp.charAt(j) == '0') zero++;
                    else one++;
                }
                freq[i][0] = zero;
                freq[i][1] = one;
            }

            int[][][] dp = new int[strs.length][m+1][n+1];

            return helper(0,freq,m,n,strs,dp);
        }
    }