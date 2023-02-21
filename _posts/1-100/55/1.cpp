class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;
        if(nums.size()==1) return 1;
        for(int i=0;i<nums.size();i++){
            m = max(m, i+nums[i]);
            if(m+1>=nums.size()) return 1;
            if(m==i) return 0;
        }
        
        return 1;
    }
};