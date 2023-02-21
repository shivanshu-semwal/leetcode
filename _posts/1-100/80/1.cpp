// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();

        int prev = nums[0];
        int c = 1;
        int j = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == prev) {
                if (c == 1) {
                    nums[j] = prev;
                    c++;
                    j++;
                } else {
                    c++;
                }
            } else {
                nums[j++] = nums[i];
                prev = nums[i];
                c = 1;
            }
        }

        return j;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 1, 1, 2, 2, 3};
    s.removeDuplicates(v);
    return 0;
}