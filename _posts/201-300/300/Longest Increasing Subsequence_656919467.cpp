class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 0);
        for(int i=0;i<n;i++){
            int m=1;
            for(int j=0;j<i;j++) if(a[j] < a[i]) m = max(m, 1+dp[j]);
            dp[i] = m;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
