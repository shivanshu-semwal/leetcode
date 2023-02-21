class Solution {
public:
    TreeNode *solve(vector<int>& nums, int l, int h){
        if(l>h) return NULL;
        int m = l + (h-l)/2;
        TreeNode *t = new TreeNode(nums[m]);
        t->left = solve(nums, l, m-1);
        t->right = solve(nums, m+1, h);
        return t;
    }
        
        
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int h = nums.size() - 1;
        return solve(nums, 0, h);
    }
};
