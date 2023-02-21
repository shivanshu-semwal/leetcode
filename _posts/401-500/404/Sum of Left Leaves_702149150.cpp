class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool left=false) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            if(left) return root->val;
            else return 0;
        } else{
            return sumOfLeftLeaves(root->left, true) + 
                sumOfLeftLeaves(root->right, false);
        }
    }
};
