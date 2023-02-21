// https://leetcode.com/problems/path-sum-iii
#include <algorithm>
#include <array>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int target;
  int solve(TreeNode *root, unordered_map<int, int> &m, int &s) {
    if (root == nullptr) return 0;
    unordered_map<int, int> l, r;
    int ll, rr;
    int left = solve(root->left, l, ll);
    int right = solve(root->right, r, rr);

    if (l.size() == 0 && r.size() == 0) {
      m[root->val]++;
    } else {
      if (l.size() == 0) {
        auto t = m.find(root -) for (auto i : r) { m[i.first] }
      } else if (r.size() == 0) {
        
      } else {
      }
    }
f
    return left + right;
  }

  int pathSum(TreeNode *root, int targetSum) {
    target = targetSum;
    unordered_map<int, int> m;
    int i = 0;
    return solve(root, m, i);
  }
};

int main() {
  vector<int> v;
  return 0;
}
