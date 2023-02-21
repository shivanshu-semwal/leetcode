class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t = headA;
        while(t->next) t=t->next;
        t->next = headB;
        
        ListNode *slow = headA;
        ListNode *fast = headA;
        
        do{
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }while(slow && fast && slow != fast);
        
        if(!slow || !fast){
            t->next = NULL;
            return NULL;
        }
        
        fast = headA;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        t->next = NULL;
        return slow;
    }
};
