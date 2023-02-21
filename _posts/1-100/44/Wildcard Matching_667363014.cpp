class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, true));
        
        for(int i=0;i<m+1;i++){ // row for pattern
            for(int j=0;j<n+1;j++){ // col for string
                
                if(i==0 && j==0) dp[i][j] = true;
                else if(i==0) dp[i][j] = false;
                else if(j==0){
                    if(p[i-1]=='*') dp[i][j]=dp[i-1][j];
                    else dp[i][j] = false;
                }
                else {
                    if(p[i-1]=='*'){
                        dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
                    } else if(p[i-1]=='?' || p[i-1]==s[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        // for(int i=0;i<m+1;i++){
        //     for(int j=0;j<n+1;j++){
        //         if(dp[i][j]) cout << "T ";
        //         else cout << "F ";
        //     }
        //     cout << endl;
        // }
        
        return dp[m][n];
    }
};
