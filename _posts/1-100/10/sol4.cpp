class Solution {
public:
    bool isMatch(string s, string p) {
        int sn = s.length(), pn = p.length();
vector<vector<bool>> dp(sn+1,vector<bool>(pn+1));
        
        dp[sn][pn] = true;
        
        for(int i = sn;i>=0;i--) {
            for(int j=pn-1;j>=0;j--) { 
                if(j+1 < pn && p[j+1]=='*'){
                    if(dp[i][j+2]){
                        dp[i][j] = true;
                    } else {
                        if(i<sn && (p[j]=='.' || s[i]==p[j])){
                            dp[i][j] = dp[i+1][j];
                        }
                        else {
                            dp[i][j] = false;
                        }
                    }
                }
                else{
                    if(i<sn && (p[j]=='.'|| s[i]==p[j])){
                        dp[i][j] = dp[i+1][j+1];
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        for(int i=0;i<=sn;i++){
            for(int j=0;j<=pn;j++){
                cout << (dp[i][j] ? "T" : "F")   << " ";
            }
            cout << "\n";
        }
        return dp[0][0];
    }
};
