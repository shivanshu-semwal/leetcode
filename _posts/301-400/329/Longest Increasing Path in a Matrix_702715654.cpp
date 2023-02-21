class Solution {
public:
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& ans, int i, int j){
        if(ans[i][j] != -1) return ans[i][j];
        int dx[] = {-1, +1, +0, +0};
        int dy[] = {+0, +0, +1, -1};
        
        int a = 1;
        for(int x=0;x<4;x++){
            int ni = i + dx[x];
            int nj = j + dy[x];
            if(ni < 0 || nj < 0 || ni >= ans.size() || nj >= ans[0].size()) continue;
            if(matrix[ni][nj] > matrix[i][j]){
                a = max(a, 1 + solve(matrix, ans, ni, nj));
            }
        }
        ans[i][j] = a;
        return a;
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        
        int a = 1;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) a = max(a, solve(matrix, ans, i, j));
        return a;
    }
};
