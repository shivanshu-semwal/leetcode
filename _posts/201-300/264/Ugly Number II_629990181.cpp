class Solution {
public:
    int nthUglyNumber(int n) {
        int p2=0, p3=0, p5 = 0;
        int mul2 = 1, mul3 = 1, mul5 = 1;
        
        int ugly[n];
        //memset(ugly, n, 0);
        
        
        for(int i=0;i<n;i++){
            
            int m = min(mul2, mul3); m = min(m, mul5);

            ugly[i] = m;
            
            if(mul2 == m) { mul2 = ugly[p2] * 2; p2++; }
            if(mul3 == m) { mul3 = ugly[p3] * 3; p3++; }
            if(mul5 == m) { mul5 = ugly[p5] * 5; p5++; }            
        }
        
        return ugly[n-1];
    }
};
