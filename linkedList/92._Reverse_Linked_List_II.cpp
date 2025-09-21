class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;//Nothing to change ...

        //From the head..
        //head should be at the position of right...
        if(left==1){
            ListNode* curr = head;
            ListNode* prev = NULL;
            for(int i=left;i<=right;i++){
                ListNode* next = curr->next;
                curr->next =  prev;
                prev = curr;
                curr= next;
            }
            head->next = curr;
            return prev;
        }
        //In between thrange (1,n)....

        ListNode* temp = head;
        for(int i=1;i<left-1;i++){
            temp = temp->next;
        }
        ListNode* tail = temp->next;
        ListNode* prev = NULL;
        ListNode* curr = tail;//last in the range (left, right)

        for(int i=left;i<=right;i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //if(right == n) right is the last , then these is nothing to assign the last element so ignore it...
        if(curr !=NULL)
            tail->next = curr;
        //update the "left-1" element...
        temp->next = prev;
        return head;
    }
};