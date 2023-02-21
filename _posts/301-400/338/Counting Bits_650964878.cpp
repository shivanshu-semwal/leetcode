class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int i=0;
        while((1<<i) <= n){
            bool k = 0;
            int change = 1<<i;
            for(int j=0;j<=n;j++){
                ans[j] += k;
                if(change == 1){
                    k = !k;
                    change = 1<<i;
                } else {
                    change--;
                }
            }
            i++;
        }
        
        return ans;
    }
};
