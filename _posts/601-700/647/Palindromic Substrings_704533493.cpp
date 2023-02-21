class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int i=0;i<n-1;i++) {
            dp[i][i+1] = (s[i]==s[i+1]) ? 1 : 0;
        }
        
        for(int k=2;k<n;k++){
            for(int i=0;i<n-k;i++){
                // [i][i+k]
                if(s[i] == s[i+k] && dp[i+1][i+k-1]==1){
                    dp[i][i+k] = 1;
                }
                else {
                    dp[i][i+k] = 0;
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                ans += dp[i][j];
                // cout << dp[i][j] << ' ';
            }
            // cout << endl;
        }
        
        return ans;
    }
};
