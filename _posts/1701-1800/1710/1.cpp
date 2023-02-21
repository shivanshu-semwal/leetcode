// https://leetcode.com/problems/maximum-units-on-a-truck

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumUnits(vector<vector<int>>& b, int t) {
    sort(
        b.begin(),
        b.end(),
        [](const vector<int>& a, const vector<int>& b) {
          return a[1] > b[1];
        });

    int ans = 0, i = 0;
    while (i < b.size() && t != 0) {
      int p = min(t, b[i][0]);
      ans += p * b[i][1];
      t -= p;
      i++;
    }
    return ans;
  }
};