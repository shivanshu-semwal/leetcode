class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        while(cur){
            if(cur->left){
                
                TreeNode *p = cur->left;
                
                while(p->right && p->right != cur) p = p->right;
                
                if(p->right){
                    p->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }else {
                    p->right = cur;
                    cur = cur->left;
                }
                
            }
            else {
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return ans;
    }
};
