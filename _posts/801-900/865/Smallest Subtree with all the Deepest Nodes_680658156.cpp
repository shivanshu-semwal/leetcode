class Solution {
public:
    
    unordered_map<TreeNode *, int> t;
    
    int getHeight(TreeNode *root){
        if(!root) return 0;
        int x = 1 + max(getHeight(root->left), getHeight(root->right));
        t[root] = x;
        return x;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        t[root] = getHeight(root);
        if(!root) return nullptr;  
        if(root->left && root->right){
            if(t[root->left] == t[root->right]) return root;
            else if(t[root->left] > t[root->right]) return subtreeWithAllDeepest(root->left);
            else return subtreeWithAllDeepest(root->right);
        }
        else if(root->left) return subtreeWithAllDeepest(root->left);
        else if(root->right) return subtreeWithAllDeepest(root->right);
        else return root;
    }
};
