class Solution {
public:
    int nthUglyNumber(int n) {
        int pointer[] = {0,0,0};
        int mul[] = {1,1,1};
        
        int ugly[n];
        memset(ugly, n, 0);
        
        
        for(int i=0;i<n;i++){
            
            int m = min(mul[0], mul[1]);
            m = min(m, mul[2]);
            
            ugly[i] = m;
            
            if(mul[0] == m) { mul[0] = ugly[pointer[0]] * 2; pointer[0]++; }
            if(mul[1] == m) { mul[1] = ugly[pointer[1]] * 3; pointer[1]++; }
            if(mul[2] == m) { mul[2] = ugly[pointer[2]] * 5; pointer[2]++; }            
        }
        
        return ugly[n-1];
    }
};
