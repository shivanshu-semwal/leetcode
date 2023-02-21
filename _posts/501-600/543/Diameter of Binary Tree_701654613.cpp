class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int diameter = 0;
        unordered_map<TreeNode*, int> depths;
        stack<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            TreeNode* node = todo.top();
            if (node -> left && depths.find(node -> left) == depths.end()) {
                todo.push(node -> left);
            } else if (node -> right && depths.find(node -> right) == depths.end()) {
                todo.push(node -> right);
            } else {
                todo.pop();
                int l = depths[node -> left], r = depths[node -> right];
                depths[node] = max(l, r) + 1;
                diameter = max(diameter, l + r);
            }
        }
        return diameter;
    }
};
