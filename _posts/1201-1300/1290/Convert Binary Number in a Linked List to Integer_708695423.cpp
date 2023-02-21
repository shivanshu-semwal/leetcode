class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        ListNode *temp = head;
        while(temp){
            ans <<= 1;
            if(temp->val) ans = ans | 1;
            temp = temp->next;
        }
        
        return ans;
    }
};
