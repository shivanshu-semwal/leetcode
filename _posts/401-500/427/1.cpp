// https://leetcode.com/problems/construct-quad-tree

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    unordered_set<string> s(words.begin(), words.end());
    vector<string> res;
    for (auto w : words) {
      int n = w.size();
      vector<int> dp(n + 1);
      dp[0] = 1;
      for (int i = 0; i < n; i++) {
        if (dp[i] == 0) continue;
        for (int j = i + 1; j <= n; j++) {
          string substr = w.substr(i, j - i);
          if (substr.length() == n) continue;
          if (s.count(substr)) dp[j] = 1;
        }
        if (dp[n]) {
          res.push_back(w);
          break;
        }
      }
    }
    return res;
  }
};