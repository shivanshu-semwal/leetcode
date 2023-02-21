class Solution {
public:
    vector<int> dp;   
    int solve(vector<int> &c, int i){
        if(dp[i] != -1) return dp[i];
        if(i==1) return c[i];
        if(i==0) return 0;
        int takei = c[i] + solve(c, i-2);
        int dtakei = solve(c, i-1);
        dp[i] = max(takei, dtakei);
        return dp[i];
    }
    int deleteAndEarn(vector<int>& nums) {
        // 0 0 2 3 4 0
        int m = *max_element(nums.begin(), nums.end());
        vector<int> count(m + 2, 0);
        for(auto i: nums) count[i]++;
        for(int i=0;i<count.size();i++){ count[i] = i * count[i];}
        //for(int i=0;i<count.size();i++){ cout << count[i] << " ";}
        dp = vector<int>(m+2, -1);
        int ans = solve(count, m);
        return ans;
    }
};
