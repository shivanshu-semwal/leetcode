class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        vector<pair<int, int>> nums(num.size(), {0,0});
        for(int i=0;i<num.size();i++){
            nums[i] = {num[i], i};
        }
        sort(nums.begin(), nums.end());
        int l=0, r=nums.size()-1;
        while(l<r){
            if(nums[l].first +nums[r].first ==target) 
                return vector<int> {nums[l].second, nums[r].second};
            else if(nums[l].first +nums[r].first < target) l++;
            else r--;
        }
        return vector<int> {0,0};
    }
};
