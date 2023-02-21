class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *t = head;
        ListNode *rev = NULL;
        
        while(t && t->next){
            t = t->next->next;
            
            ListNode *temp = rev;
            rev = head;
            head = head->next;
            rev->next = temp;
        }
        if(t){
            head = head->next;  
        }
        
        while(head && rev){
            if(head->val != rev->val) return false;
            head = head->next;
            rev = rev->next;
        }
        
        return true;
    }
};
