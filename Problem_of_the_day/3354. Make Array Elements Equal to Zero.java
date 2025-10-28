//Optimal solution..
    class Solution {
        public int countValidSelections(int[] nums) {
            int n = nums.length;
            int[] prefix = new int[n];
            int[] suffix = new int[n];

            prefix[0] = nums[0];
            suffix[n-1] = nums[n-1];

            for(int i=1,j=n-2;i<n && j>=0;i++,j--){
                prefix[i] = prefix[i-1] + nums[i];
                suffix[j] = suffix[j+1] + nums[j];
            }

            int ans = 0;
            for(int i=0;i<n;i++){
                if(nums[i] == 0){
                    ans += (prefix[i] == suffix[i] || prefix[i]+1 == suffix[i]) ? 1 : 0;
                    ans += (prefix[i] == suffix[i] || prefix[i] == suffix[i]+1) ? 1 : 0;

                }
            }
            return ans;
        }
    }

// Brute Force approach....
    class Solution {
        int helper(int[] arr,int i,int dir){
            System.out.print("Array elements:-");

            for(int k:arr){
                System.out.print(k+",");
            }

            System.out.println("index:- "+i);
            
            while(i>=0 && i<arr.length){
                // int ind = i+dir;
                System.out.print(i+",");
                if(arr[i] == 0){
                    i += dir;
                }else if(arr[i] > 0){
                    dir = -dir;
                    arr[i] = arr[i]-1;
                    i = i+dir;
                }
            }
            System.out.println();
            System.out.println("elements after");

            int c = 0;
            for(int j:arr){
                if(j==0) c++;
                System.out.print(j+",");
            }
            System.out.println();

            if(c==arr.length) return 1;
            return 0;
        }

        public int countValidSelections(int[] nums) {
            int ans = 0;
            for(int i=0;i<nums.length;i++){
                if(nums[i] == 0){
                    ans += helper(nums.clone(),i,-1);//Left
                    ans += helper(nums.clone(),i,+1);//Right
                }
            }
            return ans;
        }
    }