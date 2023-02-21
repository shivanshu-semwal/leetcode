class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(x < 0)  x = -x;
            
            if(nums[x-1] < 0){
                ans.push_back(x);
                nums[x-1] = -nums[x-1];
            }
            else {
                nums[x-1] = -nums[x-1];
            }
        }
        
        return ans;
    }
};
