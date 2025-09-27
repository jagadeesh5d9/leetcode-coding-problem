//cpp code ....
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Using max heap...
        //we can go with min heap....
        priority_queue<int>heap;

        for(int i:nums){
            heap.push(i);
        }

        while(k>1){
            heap.pop();
            k--;
        }

        return heap.top();
    }
};

//Java code ....
class Solution {
    public int findKthLargest(int[] nums, int k) {
        //using min heap...
        PriorityQueue<Integer> heap = new PriorityQueue<Integer>();

        //This will give the heap with k-largest elements from the nums array...
        for(int i:nums){
            heap.add(i);
            if(heap.size()>k){
                heap.remove();
            }
        }
        //return smallest elements from the heap with k elements...
        return heap.peek();
    }
}