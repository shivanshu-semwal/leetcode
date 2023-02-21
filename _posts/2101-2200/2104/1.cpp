// https://leetcode.com/problems/sum-of-subarray-ranges

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    // min terms
    stack<int> s;
    vector<int> l, r;
    for (int i = 0; i < n; i++) {
      while (!s.empty() && nums[s.top()] > nums[i]) s.pop();
      l.push_back(s.empty() ? -1 : s.top());
      s.push(i);
    }
    s = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
      r.push_back(s.empty() ? n : s.top());
      s.push(i);
    }
    reverse(r.begin(), r.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) ans = ans - 1l * (i - l[i]) * 1l * (r[i] - i) * 1l * nums[i];
    // max terms
    l = r = vector<int>();
    s = stack<int>();
    for (int i = 0; i < n; i++) {
      while (!s.empty() && nums[s.top()] < nums[i]) s.pop();
      l.push_back(s.empty() ? -1 : s.top());
      s.push(i);
    }
    s = stack<int>();
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && nums[s.top()] <= nums[i]) s.pop();
      r.push_back(s.empty() ? n : s.top());
      s.push(i);
    }
    reverse(r.begin(), r.end());
    for (int i = 0; i < n; i++) ans = ans + 1l * (i - l[i]) * 1l * (r[i] - i) * 1l * nums[i];
    return ans;
  }
};