// https://leetcode.com/problems/remove-duplicates-from-sorted-list

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *temp = head->next;
        ListNode *prev = head;

        while (temp) {
            if (temp->val == prev->val)
                prev->next = temp->next;
            else
                prev = temp;
            temp = temp->next;
        }

        return head;
    }
};

int main() {
    Solution s;
    // s.deleteDuplicates();
    return 0;
}