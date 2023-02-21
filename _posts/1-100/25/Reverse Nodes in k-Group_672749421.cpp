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
    ListNode* r(ListNode* head){
        if(!head && !head->next) return head;
        ListNode *t= head->next;
        ListNode *prev = head;
        while(t){
            ListNode *temp = t->next;
            t->next = prev;
            prev = t;
            t = temp;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *H = new ListNode(1, head);
        
        ListNode *t = head;
        int c = 0;
        while(t){
            t = t->next;
            c++;
        }
        if(c<k) return head;
        
        ListNode *start, *end;
        
        int no = c / k;
        // cout << "c: " << c << " no: " << no << endl;
        
        ListNode *prev = H;
        while(no--){
            start = prev->next;
            end = start;
            for(int i=1;i<k;i++) end = end->next;
            
            // cout << start->val << " " << end->val << endl;
            
            ListNode *q = end->next;
            end->next = nullptr;
            
            prev->next = r(start);
            start->next = q;
            
            prev = start;
        }
        
        return H->next;
    }
};
