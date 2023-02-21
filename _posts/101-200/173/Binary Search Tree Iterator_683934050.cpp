class BSTIterator {
public:
    
    stack<TreeNode *> t;
    
    BSTIterator(TreeNode* root) {
        pushAll(root);    
    }
    
    int next() {
        TreeNode *temp = t.top();
        t.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    void pushAll(TreeNode *x){
        if(!x) return;
        t.push(x);
        pushAll(x->left);
    }
    
    bool hasNext() {
        return !t.empty();
    }
    
};
