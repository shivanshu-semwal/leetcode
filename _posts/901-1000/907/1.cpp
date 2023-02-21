// https://leetcode.com/problems/sum-of-subarray-minimums

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long mod = 1e9 + 7;

class Solution {
public:
  int sumSubarrayMins(vector<int>& arr) {
    vector<int> l, r;

    stack<int> s;
    for (int i = 0; i < arr.size(); i++) {
      while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
      l.push_back((s.empty()) ? -1 : s.top());
      s.push(i);
    }
    s = stack<int>();
    for (int i = arr.size() - 1; i >= 0; i--) {
      while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
      r.push_back((s.empty()) ? arr.size() : s.top());
      s.push(i);
    }
    reverse(r.begin(), r.end());
    int ans;

    for (int i = 0; i < arr.size(); i++) {
      long temp = ((i - r[i]) % mod) * ((l[i] - i) % mod);
      temp = (temp * arr[i] % mod) % mod;
      ans = (ans + temp) % mod;
    }

    return ans;
  }
};