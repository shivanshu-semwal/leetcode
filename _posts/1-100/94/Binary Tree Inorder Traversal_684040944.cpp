class Solution {
public:
    vector<int> ans;
    
    void inorder(TreeNode *t){
        if(!t) return;
        inorder(t->left);
        ans.push_back(t->val);
        inorder(t->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
