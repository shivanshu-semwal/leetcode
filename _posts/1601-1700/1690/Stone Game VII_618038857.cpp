class Solution {
public:
    int max(int a, int b){
        return (a>b)?a:b;    
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> sum(n + 1);
        
        // calculate sum array
        for (int i = 0; i < n; ++i) 
            sum[i + 1] = sum[i] + stones[i]; 
        
        vector<vector<int>> dp(n, vector<int>(n));
        
        // len 2->n
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                // sum(i,j) = sum[j] - sum[i]
                dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j],
                               sum[j] - sum[i] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
