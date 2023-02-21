long mod = 1e9+7;
class Solution {
public:
    int countOrders(int n) {
        // 1 - 0
        // 2 - 1 - 3
        // 3 - 2 - 5
        // 4 - 3 - 7
        // n - n-1 - 2(n-1) + 1
        // for spaces
        
        long ans = 1;
        for(int i=2;i<=n;i++){
            long spaces = 2 * i - 1;        
            ans = (ans * (((spaces+1)*spaces)/2) % mod) % mod;
        }
        return ans;
    }
};
