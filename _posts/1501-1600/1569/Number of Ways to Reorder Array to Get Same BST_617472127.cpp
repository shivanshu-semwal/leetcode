class Solution {
public:
long NUM = 1e9 + 7;

void binomialCoeff(long n, long m, vector<vector<long>> &dp) {
    for (long i = 0; i <= n; i++) {
        long k = (i < m) ? i : m;
        for (long j = 0; j <= k; j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % NUM;
            }
        }
    }
}

long nCr(long n, long r, vector<vector<long>> &dp) {
    if (n == 0 || r == 0)
        return 1;
    else if (dp[n][r] == 0) {
        binomialCoeff(n, r, dp);
    }
    cout << "n: " << n << " r: " << r << " bc: " << dp[n][r] << endl;
    ;
    return dp[n][r];
}

long help(vector<int> &nums, vector<vector<long>> &dp) {
    if (nums.empty()) return 1;
    vector<int> left, right;
    for (long i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[0])
            left.push_back(nums[i]);
        else
            right.push_back(nums[i]);
    }
    long l = help(left, dp) % NUM;
    long r = help(right, dp) % NUM;
    long ans = nCr(left.size() + right.size(), left.size(), dp);
    long ans2 = (l * r) % NUM;
    ans = (ans * ans2) % NUM; // multiplication theorem of combination
    return ans;
}

int numOfWays(std::vector<int> &numbers) {
    vector<vector<long>> dp(1001, vector<long>(1001, 0));
    long ans = (help(numbers, dp) - 1) % NUM;
    return ans;
}
};
