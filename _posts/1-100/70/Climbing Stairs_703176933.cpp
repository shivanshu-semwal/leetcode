class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> w(n, 0);
        w[0] = 1;
        w[1] = 2;
        for(int i=2;i<n;i++){
            w[i] = w[i-1] + w[i-2];
        }
        return w[n-1];
    }
};
