class Solution {
public:
   bool isEvenOddTree(TreeNode* root) {
        if(root==NULL) return true;
       
        queue<pair<TreeNode *, bool>> q;
        
        q.push(make_pair(root, true));
        
        if(root->val % 2 == 0) return false;
       
        bool check = false;
        int no = INT_MIN;
       
        while(!q.empty()){
            
            pair<TreeNode *, bool> t = q.front();
            bool flag = t.second;
            TreeNode* temp = t.first;
            q.pop();
            
            // if(check != flag){
            //     no = temp->val;
            //     check = flag;
            // } else {
            //     if(temp->val <= no) return false;
            //     else no = temp->val;
            // }
            
            if(flag) {
                
                if(check != flag){
                    no = temp->val;
                    check = flag;
                } else {
                    if(temp->val <= no) return false;
                    else no = temp->val;
                }
                
                if(temp->left) {
                    TreeNode *child = temp->left;
                    if(child->val % 2 != 0) return false;
                    q.push(make_pair(child, !flag));
                }
                if(temp->right) {
                    TreeNode *child = temp->right;
                    if(child->val % 2 != 0) return false;
                    q.push(make_pair(child, !flag));
                }
            }
            else {
                
                if(check != flag){
                    no = temp->val;
                    check = flag;
                } else {
                    if(temp->val >= no) return false;
                    else no = temp->val;
                }
                
                if(temp->left) {
                    TreeNode *child = temp->left;
                    if(child->val % 2 == 0) return false;
                    q.push(make_pair(child, !flag));
                }
                if(temp->right) {
                    TreeNode *child = temp->right;
                    if(child->val % 2 == 0) return false;
                    q.push(make_pair(child, !flag));
                }
            }    
        }
       
        return true;
    }
};
