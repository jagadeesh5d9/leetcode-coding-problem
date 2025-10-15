//Without using extra space also we can do ...
    class Solution {
        public int maxIncreasingSubarrays(List<Integer> nums) {
            List<Integer> list = new ArrayList<>();
            int n = nums.size();
            // list.add(-1);
            for(int i=1;i<n;i++){
                if(nums.get(i) <= nums.get(i-1)){
                    list.add(i);
                }
            }
            list.add(n);

            for(int i:list)
                System.out.print(i+" ");

            if(list.size() == 1) return n/2;

            int k = 0;
            int left = list.get(0);
            int right = list.get(1) - list.get(0);
            k = Math.max(k,left/2);
            int min = Math.min(left,right);
            k = Math.max(k,min);

            for(int i=1;i<list.size();i++){
                left = list.get(i) - list.get(i-1);
                k = Math.max(k,left/2);
                if(i==list.size()-1) break;
                right = list.get(i+1) - list.get(i);
                min = Math.min(left,right);
                k = Math.max(min,k);
            }
            return k;
        }
    }

// Time complexity:
//     O(n)
// Space complexity:
//     O(list.size())
