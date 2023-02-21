class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) 
    {
        dp = vector<vector<int>> (m, vector<int> (n, -1));
        return ways(0,0,m,n);
    }
    int ways(int i,int j,int m,int n)
    {
        if(i==m || j==n)
        { 
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m-1 && j == n-1)
        {    
            return 1;
        }
        return dp[i][j] = ways(i+1,j,m,n) + ways(i,j+1,m,n);
    }
};
