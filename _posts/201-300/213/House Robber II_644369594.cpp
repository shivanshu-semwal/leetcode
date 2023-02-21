class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // i,i pair
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        // i,j pair
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = max(dp[i][i], dp[i + 1][i + 1]);
        }

        // for rest
        int c = 2;
        while (c < n) {
            if(c==3){
               for (int i = 0; i < n - c; i++) {
                int x = i;
                int y = i + c;
                dp[x][y] = max(dp[x][y-1], dp[x+1][y]);
                dp[x][y] = max(dp[x][y], nums[x] + nums[y]);
            } 
            }
            for (int i = 0; i < n - c; i++) {
                int x = i;
                int y = i + c;
                for (int j = 0; x + j + 2 <= y; j++) {
                    dp[x][y] = max(dp[x][x + j] + dp[x + j + 2][y], dp[x][y]);
                }
                dp[x][y] = max(dp[x][y], dp[x][y-1]);
                dp[x][y] = max(dp[x][y], dp[x+1][y]);
            }
            c++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }

        int ans = max(dp[0][n - 2], dp[1][n-1]);
        return ans;
    }
};
