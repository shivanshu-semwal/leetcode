class Solution {
public:
    int ans;
    int solve(TreeNode *root){
        if(!root) return 0;
        int a=solve(root->left);
        int b=solve(root->right);
        ans = max(ans, 1 + a + b);
        return max(a+1, b+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        solve(root);
        return ans-1;
    }
};
