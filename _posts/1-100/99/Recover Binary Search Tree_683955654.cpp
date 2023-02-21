class Solution {
public:
    
    vector<TreeNode *> v;
    
    void inorder(TreeNode *t){
        if(!t) return;
        inorder(t->left);
        v.push_back(t);
        inorder(t->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int i=v.size()-1;
        for(;i>0;i--){
            if(v[i-1]->val > v[i]->val){
                int j = i-1;
                while(j>=0 && v[i]->val < v[j]->val) j--;
                int temp = v[j+1]->val;
                v[j+1]->val = v[i]->val;
                v[i]->val = temp;
                break;
            }
        }
    }
};
