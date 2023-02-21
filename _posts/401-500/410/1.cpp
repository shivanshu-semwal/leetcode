// https://leetcode.com/problems/split-array-largest-sum

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print(const int& x) { cout << x; }
void print(const long& x) { cout << x; }
void print(const bool& x) { cout << (x ? "true" : "false"); }
void print(const long long& x) { cout << x; }
void print(const unsigned& x) { cout << x; }
void print(const unsigned long& x) { cout << x; }
void print(const unsigned long long& x) { cout << x; }
void print(const float& x) { cout << x; }
void print(const double& x) { cout << x; }
void print(const long double& x) { cout << x; }
void print(const char& x) { cout << (char)44 << x << (char)44; }
void print(const char* x) { cout << (char)34 << x << (char)34; }
void print(const string& x) { cout << (char)34 << x << (char)34; }
template <typename T, typename V>
void print(const pair<T, V>& x);
template <typename T>
void print(const vector<T>& x);
template <typename T>
void print(const T& x);
template <typename T, typename V>
void print(const pair<T, V>& x) {
  cout << '{';
  print(x.first);
  cout << ',';
  print(x.second);
  cout << "}";
}
template <typename T, typename V, typename U>
void print(const tuple<T, V, U>& x) {
  cout << '{';
  print(get<0>(x));
  cout << ',';
  print(get<1>(x));
  cout << ',';
  print(get<2>(x));
  cout << "}";
}
template <typename T>
void print(const vector<T>& x) {
  cout << "{";
  for (int i = 0; i < x.size(); i++) {
    print(x[i]);
    cout << (x.size() - i - 1 ? "," : "");
  };
  cout << "}";
}
template <typename T>
void print(const T& x) {
  int f = 0;
  cout << '{';
  for (auto& i : x) cout << (f++ ? "," : ""), print(i);
  cout << "}";
}
void dprint() { cout << "]\n"; }
template <typename T, typename... V>
void dprint(T t, V... v) {
  print(t);
  if (sizeof...(v)) cout << ", ";
  dprint(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)             \
  cout << "[" << #x << "] = ["; \
  dprint(x)
#else
#define debug(x...)
#endif

class Solution {
public:
  vector<vector<int>> dp;
  vector<int> arr;

  int solve(vector<int>& psum, int i, int m) {
    if (i == psum.size()) return 0;
    int ans = INT_MIN;

    if (m == 1)
      ans = psum.back() - psum[i];
    else if (psum.size() - i == m) {
      ans = *max_element(arr.begin() + i - 1, arr.end());
    } else {
      // split or not split
      ans = max(psum[i] - psum[i - 1], solve(psum, i + 1, m - 1));
      psum[i + 1] += psum[i];
      ans = min(
          ans,
          solve(psum, i + 1, m));
      psum[i + 1] -= psum[i];
    }
    debug(psum, ans, i, m);
    return ans;
  }

  int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    arr = nums;

    vector<int> psum(n + 1, 0);

    psum[0] = 0;
    for (int i = 1; i <= n; i++) {
      psum[i] = psum[i - 1] + nums[i - 1];
    }

    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    return solve(psum, 1, m);
  }
};

int main() {
  vector<int> a = {7, 2, 5, 10, 8};
  int m = 2;
  Solution s;
  cout << s.splitArray(a, m);
  return 0;
}