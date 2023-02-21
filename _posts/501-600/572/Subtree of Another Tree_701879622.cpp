class Solution {
public:
    bool solve(TreeNode *root, TreeNode *subRoot){
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val){
            bool ans=true;
            if(subRoot->left || root->left){
                if(!solve(root->left, subRoot->left)) return false;
            }
            if(subRoot->right || root->right){
                if(!solve(root->right, subRoot->right)) return false;
            }
            return true;
        } 
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val){
            bool ans=true;
            
            if(subRoot->left || root->left){
                if(!solve(root->left, subRoot->left)) ans = false;
            }
            
            if(ans == false) 
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            
            if(subRoot->right || root->right){
                if(!solve(root->right, subRoot->right)) ans = false;
            }
            
            if(ans == false) 
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            
            return true;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }
};
