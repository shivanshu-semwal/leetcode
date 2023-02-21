long mod = 1e9 + 7;
class Solution {
public:
    long fact(int n){
        if(n==0 || n==1) return 1;
        else{
            long t = fact(n-1) % mod;
            return (n * t) % mod;
        }
    }
    int noprimes(int n){
        vector<bool> flag(n+1, true);
        for(int i=2;i*i<=n;i++){
            for(int j=i+i;j<=n;j+=i){
                flag[j]  = false;
            }
        }
        int count = 0;
        for(int i=2;i<=n;i++){
            if(flag[i]) count ++;
        }
        return count;
    }
    int numPrimeArrangements(int n) {
        if(n==0) return 0;        
        int no = noprimes(n);
        long ans = (fact(no) * fact(n-no))%mod;
        return ans;
    }
};
