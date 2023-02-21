class Solution {
public:
    
    void permute(vector<vector<int>>& ans, vector<int>& nums, int idx, vector<int> &a, int x){
        for(int i=0;i<nums.size();i++){
            if(x&(1<<i)) continue;
            else {
                a[idx] = nums[i];
                if(idx == nums.size() -1 ){
                    ans.push_back(a);
                    continue;
                }
                int y = x | (1<<i);
                permute(ans, nums, idx+1, a, y);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a(nums.size(), 0);
        permute(ans, nums, 0, a, 0);
        return ans;
    }
};
