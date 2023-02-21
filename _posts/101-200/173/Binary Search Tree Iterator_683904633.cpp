/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<TreeNode *> v;
    
    int c;
    TreeNode *t;
    BSTIterator(TreeNode* root) {
        t = root;
        inorder(t);
        c=0;
    }
    
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);    
        v.push_back(root);
        inorder(root->right);            
    }
    
    int next() {
        return v[c++]->val;
    }
    
    bool hasNext() {
        return (c < v.size());  
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
