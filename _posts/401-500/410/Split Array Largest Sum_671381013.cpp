#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sum;
  vector<int> maxx;
  vector<vector<int>> dp;

  int solve(vector<int>& a, int m, int x) {
    /*
        a - array,
        m - no of splits
        x - array end position
     */
    if (dp[x][m] != -1) return dp[x][m];
    // if remaining elements are same as no of splits
    if (x == m - 1) return dp[x][m] = maxx[x];
    // only one split is remaining
    if (m == 1) return dp[x][m] = sum[x];

    int ans = INT_MAX;
    int temp = a[x];
    for (int i = x - 1; i >= m - 2; i--) {
      ans = min(
          ans,
          max(
              solve(a, m - 1, i),
              temp));
      temp += a[i];
    }
    return dp[x][m] = ans;
  }

  int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    sum = vector<int>(n, 0);
    maxx = vector<int>(n, 0);
    sum[0] = nums[0];
    maxx[0] = nums[0];
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + nums[i];
    for (int i = 1; i < n; i++) maxx[i] = max(nums[i], maxx[i - 1]);
    dp = vector<vector<int>>(n + 10, vector<int>(m + 10, -1));
    int ans = solve(nums, m, n - 1);
    return ans;
  }
};
