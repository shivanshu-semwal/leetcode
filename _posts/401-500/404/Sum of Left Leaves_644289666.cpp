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
    int summ(TreeNode* root, bool isleft){
        if(root==NULL) return 0;
        int ans = 0;
        if(root->left != NULL){
            ans += summ(root->left, true);
        }
        if(root->right != NULL){
            ans += summ(root->right, false);
        }
        if(isleft && root->right == NULL && root->left == nullptr){
            ans += root->val;
        }
        return ans;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return summ(root, false);
    }
};
