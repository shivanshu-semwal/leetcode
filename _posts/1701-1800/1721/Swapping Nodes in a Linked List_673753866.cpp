class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head) return head;
        ListNode *temp = new ListNode(1, head);
        int i;
        ListNode *t = head;
        int n = 0;
        while(t){
            t=t->next;
            n++; 
        }
        int k2 = n + 1 - k;
        if(k2==k) return head;
        
        ListNode *prev = temp;
        ListNode *a = head;
        for(i=1;i<k;i++){ a = a->next; prev=prev->next;}
        
        ListNode *prev2 = temp;
        ListNode *b = head;
        for(i=1;i<k2;i++){ b = b->next; prev2=prev2->next;}
        
        prev->next = b;
        prev2->next = a;
        
        ListNode *xx = a->next;
        a->next = b->next;
        b->next = xx;
        
        return temp->next;
    }
};
