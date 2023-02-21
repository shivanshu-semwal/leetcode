class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        if(original==target) return cloned;
        TreeNode *ans;
        if(ans = getTargetCopy(original->left, cloned->left, target)) return ans;
        return getTargetCopy(original->right, cloned->right, target);
    }
};
