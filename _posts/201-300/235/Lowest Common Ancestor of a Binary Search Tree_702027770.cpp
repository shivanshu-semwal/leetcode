class Solution {
public:
    
    TreeNode *solve(TreeNode *r, TreeNode *p, TreeNode *q){
        if(!r) return NULL;
        
        if(r->val < p->val){
            // in right subtree
            return solve(r->right, p, q);
        }
        
        if(q->val < r->val){
            // in left subtree
            return solve(r->left, p, q);
        } else {
            return r;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) return lowestCommonAncestor(root, q, p);
        return solve(root, p, q);
    }
};
