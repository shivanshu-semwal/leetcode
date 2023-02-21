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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        ListNode *final = new ListNode(-1);
        ListNode *t = final;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                t->next = list1;
                t = t->next;
                list1 = list1->next;
            } else {
                t->next = list2;
                t = t->next;
                list2 = list2->next;
            }
        }
        while(list1 != nullptr){
            t->next = list1;
            t = t->next;
            list1 = list1->next; 
        }
        while(list2 != nullptr){
            t->next = list2;
            t = t->next;
            list2 = list2->next; 
        }
        t->next = nullptr;
        return final->next;
    }
};
