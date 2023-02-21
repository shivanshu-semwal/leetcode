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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr) return head;
        
        vector<ListNode *> ans;
        ListNode *temp = head;
        while(temp){
            ans.push_back(temp);
            temp = temp->next;
        }
        
        for(int i=0;i<ans.size()-1;i+=2){
            ListNode *t = ans[i];
            ans[i] = ans[i+1];
            ans[i+1] = t;
        }
        
        for(int i=0;i<ans.size()-1;i++){
            ans[i]->next = ans[i+1];    
        }
        ans.back()->next = nullptr;
        
        return ans[0];
    }
};
