class Solution {
public:
    long long dp[100005];
    long long helper(int cur_i, vector<vector<int>> &questions) {
        if (cur_i >= questions.size()) return 0;
        if (dp[cur_i] != -1) {
            return dp[cur_i];
        } else {
            long long a = questions[cur_i][0] + helper(cur_i + questions[cur_i][1] + 1, questions);
            long long b = helper(cur_i + 1, questions);
            dp[cur_i] = std::max(a, b);
            return dp[cur_i];
        }
    }

    long long mostPoints(vector<vector<int>> &questions) {
        memset(dp, -1, sizeof(dp));
        return helper(0, questions);
    }
};
