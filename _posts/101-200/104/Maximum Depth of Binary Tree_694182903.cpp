class Solution {
public:
    int maxDepth(TreeNode* root, int ans = 0) {
        if(!root) return ans;
        return max(maxDepth(root->left, ans + 1), maxDepth(root->right, ans + 1));
    }
};
