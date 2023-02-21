class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * t= new ListNode(0);
        t->next = head;
        
        ListNode *prev = t;
        ListNode *p = head;
        while(p){
            if(p->val == val) p = p->next;
            else {
                prev->next = p;
                p=p->next;
                prev = prev->next;
            }
        }
        prev->next = NULL;
        return t->next;
    }
};
