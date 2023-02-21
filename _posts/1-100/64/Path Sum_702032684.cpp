
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        if(!root->left && !root->right){
            targetSum -= root->val;
            if(targetSum == 0) return true;
            else return false;
        } else{
            return hasPathSum(root->left, targetSum - root->val) ||
                    hasPathSum(root->right, targetSum - root->val);
        }
    }
};
