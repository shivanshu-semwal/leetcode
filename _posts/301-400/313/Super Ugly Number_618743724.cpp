class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        
        if (n == 1) return 1;
        long ugly[n];
        for(int i=0;i<n;i++) ugly[i] = 0;
        
        long count[primes.size()];
        for(int i=0;i<primes.size();i++) count[i] = 0;
        
        long multiples[primes.size()];
        for(int i=0;i<primes.size();i++) multiples[i] = 1;
        
        long next = 1;
        for(int i=0;i<n;i++){
            ugly[i] = next;
            next = INT_MAX;
            for(int j=0;j<primes.size();j++){
                if(multiples[j] == ugly[i]){
                    multiples[j] = ugly[count[j]++] * primes[j];
                }
                if(next > multiples[j]){
                    next = multiples[j];
                }
            }
        }
        
        return ugly[n-1];
    }
};
