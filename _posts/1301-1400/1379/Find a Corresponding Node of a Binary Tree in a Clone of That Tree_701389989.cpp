class Solution {
public:
    TreeNode *find(TreeNode *root, TreeNode *c, TreeNode *t){
        if(!root) return NULL;
        if(root == t) return c;
        else {
            TreeNode *left = find(root->left, c->left, t);
            if(left) return left;
            TreeNode *right = find(root->right, c->right, t);
            return right;
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!target) return NULL;
        return find(original, cloned, target);
    }
};
