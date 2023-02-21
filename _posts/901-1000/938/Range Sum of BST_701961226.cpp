class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        if(high < root->val) return rangeSumBST(root->left, low, high);
        else if(root->val < low) return rangeSumBST(root->right, low, high);
        else {
            return root->val + rangeSumBST(root->left, low, root->val) + rangeSumBST(root->right, root->val, high);
        }
    }
};
