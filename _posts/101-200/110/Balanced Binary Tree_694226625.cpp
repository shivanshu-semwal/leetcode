class Solution {
public:
    
    int getHeight(TreeNode *root, bool &ans){
        if(!root) return 0;
        
        if(ans == false) return -1;
        
        int l = (root->left) ? 1 + getHeight(root->left, ans):0;
        int r = (root->right) ? 1 + getHeight(root->right, ans):0;
        
        if(abs(l-r) > 1){
            ans = false;
        }
        
        return max(l, r);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        getHeight(root, ans);
        return ans;
    }
};
