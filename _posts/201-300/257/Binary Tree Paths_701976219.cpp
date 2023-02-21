class Solution {
public:
    vector<string>  ans;
        
    void solve(TreeNode *root, string &a){
        if(!root) return;        
        a = a + "->" + to_string(root->val);      
        if(!root->left && !root->right){
            ans.push_back(a);
            return;
        }
        
        string temp = a;
        solve(root->left, a);
        a = temp;
        solve(root->right, a);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return vector<string>();
        string a;      
        a = to_string(root->val);
        
        if(!root->left && !root->right){
            return vector<string> {a};    
        }
        solve(root->left, a);
        
        a = to_string(root->val);
        solve(root->right, a);
        
        return ans;
    }
};
