class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;//For the previous node...
        ListNode* curr = head;//current element
        ListNode* next;
        while(curr!= NULL){
            next = curr->next;//Store the next of the curr
            curr->next = prev;//update 
            prev = curr;//move the prev
            curr = next;
        }
        return prev;//will be the head after reversing the element...
    }
};