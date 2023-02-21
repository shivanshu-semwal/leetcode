class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *t = new ListNode(INT_MAX);
        t->next = head;
        
        ListNode *prev = t;
        ListNode *cur = head;
        while(cur){
            if(cur->val == prev->val){
                cur=cur->next;
                prev->next = NULL;
            }
            else {
                prev->next = cur; 
                cur = cur->next;
                prev = prev->next;
            }
        }
        return t->next;
    }
};
