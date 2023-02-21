class Solution {
public:
    
    bool valid(TreeNode *root, long left, long right){
        if(!root) return true;
        if(root->val < right && root->val > left){
            bool ans = true;
            if(root->left){
                ans = valid(root->left, left, root->val);
            }
            if(root->right){
                ans = ans && valid(root->right, root->val, right);
            }
            return ans;
        } else {
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};
