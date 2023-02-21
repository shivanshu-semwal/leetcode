class Solution {
public:
    enum state {COVERME, COVERED, CAMERA};
    int camera;
    
    Solution(){
        camera = 0;
    }
    
    state solve(TreeNode *root){
        if(root==nullptr) return COVERED;
        if(root->left == nullptr && root->right == nullptr) return COVERME;
        
        state left = solve(root->left);
        state right = solve(root->right);
        
        if(left == COVERME || right == COVERME){
            camera++;
            return CAMERA;
        }
        if(left == CAMERA || right == CAMERA) return COVERED;
        return COVERME;
    }
    
    int minCameraCover(TreeNode* root) {
        if(solve(root) == COVERME) return camera+1;
        else return camera;
    }
};
