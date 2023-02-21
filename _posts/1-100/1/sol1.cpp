class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> ans(n);
        for (int i = 0; i < n; i++) ans[i] = {nums[i], i};
        sort(ans.begin(), ans.end());
        for (int start = 0, end = n - 1;;) {
            int sum = ans[start].first + ans[end].first;
            if (sum == target) {
                // solution always exists
                return vector<int>{ans[start].second, ans[end].second};
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }
        return vector<int>{0,0};
    }
};
