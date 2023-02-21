class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>();
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        
        vector<int> temp;
        
        while(!q.empty()){
            TreeNode *t = q.front();
            q.pop();
            if(t==NULL){
                ans.push_back(temp);
                temp=vector<int>();
                if(!q.empty()) q.push(NULL);
                continue;
            }
            
            temp.push_back(t->val);
            
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        
        
        return ans;
    }
};
