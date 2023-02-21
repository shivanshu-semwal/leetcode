class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            if(a[i-1] < a[i]) dp[i] = dp[i-1] + 1;
            else dp[i] = 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
