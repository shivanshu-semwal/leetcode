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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    ListNode* pt1 = l1;
    ListNode* pt2 = l2;

    int sum = pt1->val + pt2->val;
    int carry = sum / 10;
    sum %= 10;
    ListNode* ans = new ListNode(sum);
    ListNode* anstemp = ans;
    pt1 = pt1->next;
    pt2 = pt2->next;

    while (pt1 != NULL && pt2 != NULL) {
      sum = pt1->val + pt2->val + carry;
      carry = sum / 10;
      sum %= 10;
      ans->next = new ListNode(sum);
      ans = ans->next;
      pt1 = pt1->next;
      pt2 = pt2->next;
    }

    if (pt1 != NULL) {
      while (pt1 != NULL) {
        sum = pt1->val + carry;
        carry = sum / 10;
        sum %= 10;
        ans->next = new ListNode(sum);
        ans = ans->next;
        pt1 = pt1->next;
      }
    } else if (pt2 != NULL) {
      while (pt2 != NULL) {
        sum = pt2->val + carry;
        carry = sum / 10;
        sum %= 10;
        ans->next = new ListNode(sum);
        ans = ans->next;
        pt2 = pt2->next;
      }
    }
    if (carry != 0) {
      ans->next = new ListNode(carry);
    }
    return anstemp;
  }
};
