/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *start = new ListNode(INT_MAX);
        ListNode *temp = start;
        start->next = head;
        ListNode *start2 = head;
        ListNode *t = head->next;
        
        while(t!=nullptr){
            if(t->val == start2->val){
                // remove node
                while(t!=nullptr && t->val == start2->val) t=t->next;
                start->next = t;
                start2 = t;
                if(t!=nullptr) t = t->next;
            } else {
                start = start2;
                start2 = t;
                t = t->next;
            }
        }
        return temp->next;
    }
};
