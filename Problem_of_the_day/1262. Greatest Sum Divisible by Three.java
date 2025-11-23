//Optimized solution without using array....

    class Solution {
        public int maxSumDivThree(int[] nums) {
            int s0=0,s1=0,s2=0;
            int b0=0,b1=0,b2=0;

            for(int i:nums){
                int m0 = (s0+i) % 3;
                int m1 = (s1+i) % 3;
                int m2 = (s2+i) % 3;

                if(m0 == 0) b0 = Math.max(b0,s0+i);
                else if(m0 == 1) b1 = Math.max(b1,s0+i);
                else b2 = Math.max(b2,s0+i);
                
                if(m1 == 0) b0 = Math.max(b0,s1+i);
                else if(m1 == 1) b1 = Math.max(b1,s1+i);
                else b2 = Math.max(b2,s1+i);

                if(m2 == 0) b0 = Math.max(b0,s2+i);
                else if(m2 == 1) b1 = Math.max(b1,s2+i);
                else b2 = Math.max(b2,s2+i);

                s0 = b0;
                s1 = b1;
                s2 = b2;

            }

            return s0;
        }
    }
    

//Recursive solution without dp...
    class Solution {
        int ans = 0;
        void helper(int i,int[] nums, int n,int sum,int[][] dp){
            //base case...
            if(i == n) return ;

            //Not take...
            // ArrayList<Integer> temp = new ArrayList<>();
            
            if(sum % 3 == 0){
                ans = Math.max(ans,sum);
                // for(int ip:temp)
                //     System.out.print(ip+',');
                // System.out.println();
            }

            helper(i+1,nums,n, sum,temp);

            //Take...
            if((sum+nums[i]) % 3 == 0){
                ans = Math.max(ans,sum+nums[i]);
                // for(int ip:temp)
                //     System.out.print(ip+',');
                // System.out.println();
            }

            temp.add(i);

            helper(i+1,nums,n,sum+nums[i],temp);
            temp.remove(temp.size()-1);

        }

        public int maxSumDivThree(int[] nums) {
            int sum = 0;
            for(int i:nums) sum += i;

            int[][] dp = new int[nums.length][sum];
            helper(0,nums,nums.length,0,dp);
            return ans;
        }
    }


