class Solution {
public:
    vector<pair<int, int>> a;
    int dp[101][101][600];
    
    int solve(int m, int n, int idx){
        if(idx == -1) return 0;
        if(m==0 && n==0) return 0;
        if(dp[m][n][idx] != -1) return dp[m][n][idx];
        
        if(a[idx].first > m || a[idx].second > n){
            int t = solve(m, n, idx-1);
            dp[m][n][idx] = t;
            return t;
        }
        else {
            int t = max(solve(m, n, idx-1), 1 + solve(m-a[idx].first, n-a[idx].second, idx-1));
            dp[m][n][idx] = t;
            return t;
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<strs.size();i++){
            int zero = 0, one = 0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0') zero++;
                else one++;
            }
            a.push_back({zero, one});
        }
        
        return solve(m, n, a.size()-1);
    }
};
