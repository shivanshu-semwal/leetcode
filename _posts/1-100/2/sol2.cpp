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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int bal = 0) {
    if (l1 == NULL && l2 == NULL) {
      if (bal == 0)
        return NULL;
      else
        return new ListNode(bal);
    }
    if (l1 == NULL) {
      int no = l2->val + bal;
      l2->val = no % 10;
      l2->next = addTwoNumbers(l1, l2->next, no / 10);
      return l2;
    }
    if (l2 == NULL) {
      int no = l1->val + bal;
      l1->val = no % 10;
      l1->next = addTwoNumbers(l1->next, l2, no / 10);
      return l1;
    }
    int no = l1->val + l2->val + bal;
    ListNode* p = new ListNode(no % 10);
    p->next = addTwoNumbers(l1->next, l2->next, no / 10);
    return p;
  }
};
