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
    ListNode* solve(ListNode* head, int n) {
        ListNode *t = new ListNode(1);
        t->next = head;
        
        ListNode *prev = t;
        ListNode *cur = t->next;
        n--;
        while(n--){
            prev = cur;
            cur = cur->next;
            //cout << cur->val << endl;
        }
        prev->next = cur->next;
        return t->next;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int c=0;
        while(head){
            head = head->next;
            c++;
        }
        //cout << c << " ";
        //return head;
        return solve(temp, c-n+1);
    }
};
