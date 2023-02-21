class Solution {
public:
    
    int dp[100000][12];
    
    int solve(vector<int> &c, int a, int idx){
        if(idx==-1) {if(a != 0) return INT_MAX - 1; else return 0;}
        if(a == 0) return 0;

        if(dp[a][idx] != -1) return dp[a][idx];
        
        if(c[idx] > a) return dp[a][idx] = solve(c, a, idx-1);
        else 
            return dp[a][idx] = 
            min(solve(c, a, idx-1),1 + solve(c, a-c[idx], idx));
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int minc = solve(coins, amount, coins.size()-1);
        return minc == INT_MAX - 1 ? -1 : minc;
    }
};


