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
    void dfs(TreeNode *root, TreeNode *temp) {
      if (root == NULL) return;

      temp->val = root->val;
      temp->right = new TreeNode();
      temp->left = NULL;
      
      dfs(root->left, temp->right);
      
      while(temp->right != NULL){
        temp = temp->right;
      }
      
      dfs(root->right, temp);
    }

    void flatten(TreeNode *root) {
        if(root==NULL) return;
        TreeNode *temp = new TreeNode(root->val);
        dfs(root, temp);
        TreeNode *temp2 = temp;
        while((temp2->right)->right !=NULL){
          temp2 = temp2->right;
        }
        temp2->right = NULL;
        root->left = NULL;
        root->right = temp->right;
    }
};
