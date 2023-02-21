class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int bal = 0) {
    if (!l1 && !l2) return (bal != 0) ? new ListNode(bal) : nullptr;
    int no = bal;
    if (l1) {
      no += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      no += l2->val;
      l2 = l2->next;
    }
    return new ListNode(no % 10, addTwoNumbers(l1, l2, no / 10));
  }
};
