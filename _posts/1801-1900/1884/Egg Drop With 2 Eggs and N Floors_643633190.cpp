class Solution {
public:
    int *dp;
    int ans(int n){
        if(dp[n]!=0) return dp[n];
        int m = n;
        int temp, temp2;
        for (int i=1;i<=n;i++){
            temp = i-1;
            temp2 = ans(n-i);
            m = min(m,1 + max(temp, temp2));
        }
        dp[n] = m;
        return m; 
    }
    int twoEggDrop(int n) {
        dp = new int[n+10]{0, 1, 2};
        return ans(n);
    }
};
