/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode *, int>> q;
        int max_level = 0;
        int cur_level = 0;
        TreeNode *prev = root;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode *, int> t = q.front();
            q.pop();
            TreeNode *temp = t.first;
            int cur_level = t.second;
            if(cur_level > max_level){
                ans.push_back(prev->val);
                max_level = cur_level;
            }
            if(temp->left) q.push(make_pair(temp->left, cur_level + 1));
            if(temp->right) q.push(make_pair(temp->right, cur_level + 1));
            prev = temp;
        }
        ans.push_back(prev->val);
        return ans;
    }
};
