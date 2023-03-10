/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, bool> m;
        while(head != nullptr){
            if(m.find(head) != m.end()) return true;
            m[head] = true;
            head = head->next;
        }
        return false;
    }
};
