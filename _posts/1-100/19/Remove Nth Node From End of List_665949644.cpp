class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head;
        ListNode **slow=&head;
        while(n--) fast = fast->next;
        while(fast) {
            fast = fast->next;
            slow = &((*slow)->next);
        }
        (*slow) = ((*slow)->next);
        return head;
    }
};
