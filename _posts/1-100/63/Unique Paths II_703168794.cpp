class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<long>> ans(n, vector<long> (m, 0));
        
        if(g[n-1][m-1]==1) return 0;
        ans[n-1][m-1] = 1;
        
        for(int j=m-2;j>=0;j--){
            if(g[n-1][j]==1) ans[n-1][j] = 0;
            else ans[n-1][j] = ans[n-1][j+1];
        }
        
        for(int i=n-2;i>=0;i--){
            if(g[i][m-1]==1) ans[i][m-1] = 0;
            else ans[i][m-1] = ans[i+1][m-1];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(g[i][j] == 1) ans[i][j] = 0;
                else ans[i][j] = ans[i+1][j] + ans[i][j+1];
            }
        }
        
        return ans[0][0];
    }
};
