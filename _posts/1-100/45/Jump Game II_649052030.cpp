class Solution {
public:
    int helper(vector<int> &nums, int start, int end){
        cout << start << " " << end << endl;
        if(end >= nums.size() - 1) return 0;
        
        int m = INT_MIN;
        for(int i=end;i>=start;i--){
            m = max(m, nums[i] + i);
        }
        return 1 + helper(nums, end+1, m);
    }
    
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        return helper(nums, 0, 0); 
    }
};
