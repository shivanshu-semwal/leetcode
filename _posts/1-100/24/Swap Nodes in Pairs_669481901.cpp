class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* a = head;
        ListNode* b = head->next;
        head = head->next;
        
        while(b){
            if(prev) prev->next = b;
            a->next = b->next;
            b->next = a;
            
            prev = a;            
            a = a->next;
            if(a) b = a->next;
            else b=nullptr;
        }
        
        return head;
    }
};
