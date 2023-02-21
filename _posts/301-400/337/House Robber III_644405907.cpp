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
class Solution {
public:
    void robb(TreeNode *root, int &level2, int &level1) {
        if(root == nullptr) return;
        
        int leftlevel2=0, rightlevel2=0, leftlevel1=0, rightlevel1=0;
        if(root->left){
            robb(root->left, leftlevel2, leftlevel1);
        }
        if(root->right){
            robb(root->right, rightlevel2, rightlevel1);
        }
        
        // include this node
        int ans1 = 0;
        ans1 = root->val + leftlevel2 + rightlevel2;      
        
        // don't include this node
        int ans2 = 0;
        ans2 = leftlevel1 + rightlevel1;
        
        level1 = max(ans1, ans2);
        level2 = ans2; 
    }
    
    int rob(TreeNode* root) {
        int ans1, ans2;
        robb(root, ans1, ans2);
        return ans2;
    }
};
