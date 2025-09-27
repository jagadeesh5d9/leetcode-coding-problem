//Cpp solution....
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
     */
    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<int,vector<int>,greater<int>>heap;
            for(ListNode* i:lists){
                ListNode* temp = i;
                while(temp!=NULL){
                    heap.push(temp->val);
                    temp= temp->next;
                }
            }
            //If there is no elements in the given "lists"
            if(heap.empty()) return NULL;

            ListNode* head = new ListNode(heap.top(),NULL);
            ListNode* temp = head;
            heap.pop();
            while(!heap.empty()){
                ListNode* newNode = new ListNode(heap.top(),NULL);//call the constructor...
                temp->next = newNode;
                temp = newNode;
                heap.pop();
            }
            return head;
        }
    };

//Java solution...
    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode() {}
     *     ListNode(int val) { this.val = val; }
     *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
     * }
     */
    class Solution {
        public ListNode mergeKLists(ListNode[] lists) {
            PriorityQueue<Integer> heap = new PriorityQueue<Integer>();
            for(ListNode i:lists){
                ListNode temp = i;
                while(temp!=null){
                    heap.add(temp.val);
                    temp = temp.next;
                }
            }
            if(heap.isEmpty()) return null;
            
            ListNode head = new ListNode(heap.peek(),null);
            ListNode temp = head;
            heap.remove();
            while(!heap.isEmpty()){
                ListNode newNode = new ListNode(heap.peek(),null);
                temp.next = newNode;
                temp = newNode;
                heap.remove();
            }
            return head;
        }
    }