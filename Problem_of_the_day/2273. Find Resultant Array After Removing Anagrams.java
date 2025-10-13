// Approach-1 : Using Two pointer 

    // Time complexity : O(n * k* log k)
    // Space complexity : O(n)
    class Solution {
        public List<String> removeAnagrams(String[] words) {
            // HashMap<String,Integer> map = new HashMap<>();
            List<String> ans = new ArrayList<>();
            int n = words.length;

            int i =0;
            while(i<n){
                ans.add(words[i]);
                int j = i+1;
                // int v = 1;
                //Make the string in sorted order...
                char[] prev = words[i].toCharArray();
                Arrays.sort(prev);
                String temp = new String(prev);

                while(j<n){
                    char[] curr = words[j].toCharArray();
                    Arrays.sort(curr);
                    String temp1 = new String(curr);
                    if(temp.equals(temp1)){
                        j++;
                    }else{
                        break;
                    }
                }
                i = j;
            }
            return ans;

        }
    }

//we can solve this in many ways 
    // - using multi dimensional vector "map inside the vector or array"
    // By stroing the previous val and check current string is a anagram or not (Without using the two pointer...)