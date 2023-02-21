int dp[20000];
class Solution {
public:
    int solve(vector<int>& a, vector<int>& b, int i, int mask) {
        if(i >= a.size()) return 0;
        if(dp[mask] == INT_MAX){
            for(int j=0;j<b.size(); j++){
                if(!(mask & (1<<j))){
                   dp[mask] = min(dp[mask], (a[i] ^ b[j]) + solve(a, b, i+1, mask + (1<<j)));
                }
            }
        }
        return dp[mask];
    }
    int minimumXORSum(vector<int>& a, vector<int>& b) {
        std::fill_n(dp, 20000, INT_MAX);
        return solve(a, b, 0, 0);
    }
};
