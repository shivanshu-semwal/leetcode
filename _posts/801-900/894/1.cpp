// https://leetcode.com/problems/all-possible-full-binary-trees

#include <algorithm>
#include <array>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  vector<TreeNode*> allPossibleFBT(int n) {
    if (n % 2 == 0) return vector<TreeNode*>();
    if (n == 1) return vector<TreeNode*>{new TreeNode()};
    if (n == 3) return vector<TreeNode*>{
        new TreeNode(0, new TreeNode(), new TreeNode())};

    unordered_map<int, vector<TreeNode*>> m;
    for (int i = 1; i < n; i += 2) m[i] = allPossibleFBT(i);

    vector<TreeNode*> ans;
    for (int ii = 1; ii < n; ii += 2) {
      auto left = m.find(ii);
      for (int i = 0; i < left->second.size(); i++) {
        auto right = m.find(n - ii - 1);
        for (int j = 0; j < right->second.size(); j++) {
          TreeNode* t = new TreeNode(0, left->second[i], right->second[j]);
          ans.push_back(t);
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
