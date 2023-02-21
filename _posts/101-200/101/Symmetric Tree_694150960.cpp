class Solution {
public:
    bool valid(TreeNode *l, TreeNode *r){
        if(l->val == r->val){
            bool ans = true;
            
            if(l->left && r->right) ans = valid(l->left, r->right);
            if(l->right && r->left) ans = ans && valid(l->right, r->left);

            if(l->left && !r->right) return false;
            if(!l->left && r->right) return false;
            if(l->right && !r->left) return false;
            if(!l->right && r->left) return false;
            
            return ans;

        } else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return valid(root, root);
    }
};
