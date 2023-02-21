// https://leetcode.com/problems/rotate-list

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int n=0;
        ListNode *temp = head;
        ListNode *end;
        while(temp){
            n++;
            if(temp->next == nullptr) end = temp;
            temp = temp->next;
        }
        
        k = (k%n == 0) ? n : (k%n);
        k = n - k;
        
        if(k==0) return head;
        
        ListNode *prev = new ListNode(0, head);
        
        for(int i=0;i<k;i++) {
            prev = prev->next;
        }
        cout << prev->val << endl;
        temp = prev->next;
        prev->next = nullptr;
        end->next = head;
        
        return temp;
    }
};