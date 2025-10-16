class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        HashMap<Integer,Integer> map = new HashMap<>();
        //Store the key-value pair of remainders -> (x+k.value)%value = x%value;
        for(int i:nums){
            int rem;
            if(i<0){//For finding the remainders of negative numbers...
                int abs = Math.abs(i);
                rem = (value - (abs%value)) % value;
            }else{
                rem = i % value;
            }
            map.put(rem, map.getOrDefault(rem,0)+1);
        }

        for(int k:map.keySet()){
            System.out.println(k+"->"+map.get(k));
        }

        int temp =0;
        int last = (int)(1e5+1);//Based on the contraints , we set the last value....
        while(temp<last){
            int r = temp%value;//Check for the remainder
            if(map.getOrDefault(r,0) ==0) return temp;
            map.put(r,map.get(r)-1);
            temp++;
        }
        //Optional..
        return temp;
    }
}