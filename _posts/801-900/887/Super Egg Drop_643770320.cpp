class Solution {
public:
    vector<vector<int>> dp;

    /* f(t,n) = m, m is min value for a broken egg */
    int f(int t, int n) {
        if (dp[t][n] != 0) return dp[t][n];
        if (t == 0) {
            dp[t][n] = 1;
        } else if (n == 0) {
            dp[t][n] = 1;
        } else {
            dp[t][n] = f(t - 1, n - 1) + f(t - 1, n);
        }
        return dp[t][n];
    }

    int ans(int n, int k) {
        dp[0][n] = 1; // 0 tries, n eggs
        if (dp[0][n] > k) return 0;
        for (int i = 1; i <= k; i++) {
            dp[i][n] = f(i - 1, n - 1) + f(i - 1, n);
            if (dp[i][n] > k) return i;
        }
        return k;
    }

    int superEggDrop(int n, int k) {
        // n - no of eggs
        // k - no of floors
        // t - no of tries
        dp = vector<vector<int>>(k + 10, vector<int>(n + 10, 0));
        return ans(n, k);
    }
};
