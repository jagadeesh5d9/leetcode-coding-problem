//Solution with Recursion...
    class Solution {
        public int minNo(ArrayList<Integer> target) {
            int min = Integer.MAX_VALUE;
            for (int i : target) {
                min = Math.min(min, i);
            }
            return min;
        }

        int helper(ArrayList<Integer> arr) {
            if (arr.size() == 0) return 0;

            int min = minNo(arr);
            for (int i = 0; i < arr.size(); i++) {
                arr.set(i, arr.get(i) - min);
            }

            int ans = min;
            ArrayList<Integer> arr1 = new ArrayList<>();

            for (int i : arr) {
                if (i == 0) {
                    ans += helper(arr1);
                    arr1 = new ArrayList<>();
                    continue;
                }
                arr1.add(i);
            }
            ans += helper(arr1);
            return ans;
        }

        public int minNumberOperations(int[] target) {
            ArrayList<Integer> arr = new ArrayList<>();
            for (int i : target) arr.add(i);
            return helper(arr);
        }
    }

//Better approach
    //just building logic by thinking...
    //Whether Current element is covered by previous element or not. i.e. valid subarray or not when it reduce by 1 ...
    class Solution {
        public int minNumberOperations(int[] target) {
            int ans = target[0];
            for (int i = 1; i < target.length; i++) {
                if (target[i] > target[i - 1]) {
                    ans += target[i] - target[i - 1];
                }
            }
            return ans;
        }
    }

