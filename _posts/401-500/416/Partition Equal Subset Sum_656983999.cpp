class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        int m = sum/2;
        int n=nums.size();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        
        // dp[i][j] - represents can we make j weight form first i elements
        // dp[i][j] = dp[i-1][j] || dp[i][w-j]
        
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            dp[i][0] = true;
            for(int j=1;j<=m;j++){
                if(j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(auto i:dp){ 
        //     for(auto j:i){ 
        //         if(j) cout << "T ";
        //         else cout << "F ";
        //     }
        //     cout << endl;
        // }
        return dp[n][m];
    }
};
