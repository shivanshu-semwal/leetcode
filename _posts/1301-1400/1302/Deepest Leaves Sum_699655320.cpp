class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        long sum = 0;
        while(!q.empty()){
            TreeNode *c = q.front();
            q.pop();
            
            if(c == NULL){
                if(q.empty()) break;
                q.push(NULL);
                sum = 0;
                continue;
            }
            if(c->left) q.push(c->left);
            if(c->right) q.push(c->right);
            sum += c->val;
        }
        
        return sum;
    }
};
