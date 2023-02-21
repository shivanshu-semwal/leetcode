class Solution {
public:
    vector<vector<int>> dp;
    // int dp[10000 + 1][12 + 1];

    int solve(vector<int>& coins, int amount, int n) {
        if (n == 0 || amount == 0) {
            if (amount == 0) {
                return 0;
            } else {
                return INT_MAX - 1;
            }
        }
        if (dp[amount][n] != -1) {
            return dp[amount][n];
        }
        if (coins[n - 1] > amount) {
            dp[amount][n] = solve(coins, amount, n - 1);
            return dp[amount][n];
        } else {
            dp[amount][n] = min(solve(coins, amount, n - 1),
                                1 + solve(coins, amount - coins[n - 1], n));
            return dp[amount][n];
        }
    }

    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        dp = vector<vector<int>>(amount+1, vector<int>(n+1,-1));
        // memset(dp, -1, sizeof(dp));
        int ans = solve(coins, amount, n);
        return (ans == INT_MAX - 1) ? -1 : ans;
    }
};
