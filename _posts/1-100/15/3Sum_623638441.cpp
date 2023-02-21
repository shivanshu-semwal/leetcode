class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int j = i+1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sol.push_back(temp);
                    while (j < k && nums[j] == temp[1]) j++;
                    while (j < k && nums[k] == temp[2]) k--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return sol;
    }
};

