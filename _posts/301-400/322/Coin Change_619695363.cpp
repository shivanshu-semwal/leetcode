class Solution {
public:
    int dp[10000 + 1][12 + 1];
    
    int memoization(vector<int>& wt, int w, int n)
    {
        if (n == 0 || w == 0){
            if(w==0){
                return 0;
            } else {
                return INT_MAX -1;
            }
        }
            // return (w == 0) ? 0 : INT_MAX - 1;
        
        if (dp[w][n] != -1)
            return dp[w][n];
            
        if (wt[n - 1] > w) {
            dp[w][n] = 0 + memoization(wt, w, n - 1);
            return dp[w][n];
        }
        else{ 
            dp[w][n] = min(memoization(wt, w, n - 1), 1 + memoization(wt, w - wt[n - 1], n));
            return dp[w][n];
        }
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int minCoins = memoization(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;    
    }
};
