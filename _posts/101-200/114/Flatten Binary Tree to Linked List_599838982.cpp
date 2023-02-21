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
    void fix(TreeNode *root){
      if(root == NULL) return;
      fix(root->left);
      fix(root->right);
      if(root->left != NULL){
        if(root->right != NULL){
          TreeNode* temp = (root->left)->right;
          if(temp==NULL){
            (root->left)->right = root->right;
            root->right = root->left;
            root->left = NULL;
          } else{          
            while(temp->right != NULL){
              temp = temp->right;
            }
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
          }
        } else {
          root->right = root->left;
          root->left = NULL;
        }
      }
    }
    void flatten(TreeNode* root) {
        fix(root);
    }
};
