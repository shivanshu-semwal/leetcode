class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> a(n+10, 0);
        if(n==0) return 0;
        if(n==1) return 1;
        int max = 1;
        a[0] = 0;
        a[1] = 1;
        for(int i=2;i<=n;i++){
            if(i&1){
                a[i] = a[(i-1)/2] + a[(i-1)/2 + 1];
            } else {
                a[i] = a[i/2];
            }
            if(a[i] > max) max = a[i];
        }
        return max;
    }
};
