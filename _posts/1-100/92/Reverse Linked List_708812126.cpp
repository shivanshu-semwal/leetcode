class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        
        while(head){
            ListNode *tmp = prev;
            prev = head;
            
            head = head->next;
            
            prev->next = tmp;
        }
        
        return prev;
    }
};
