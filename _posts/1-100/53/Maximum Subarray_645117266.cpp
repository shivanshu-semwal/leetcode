class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        int max_h = 0;
        for(int i=0;i<n;i++){
            max_h += nums[i];
            if(max < max_h) max = max_h;
            if(max_h < 0) max_h = 0; // reset it
        }
        return max;
    }
};
