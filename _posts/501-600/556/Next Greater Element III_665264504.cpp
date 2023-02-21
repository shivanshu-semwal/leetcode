class Solution {
public:
    int reverse(int x){
        int t=0;
        while(x){
            t = t * 10 + x%10;
            x /= 10;
        }
        return t;
    }
    int nextGreaterElement(int n) {
        long n2=n;
        long x = 10;
        while(n2 > 9 &&  ((n2%100)/10) >= n2%10 ){
            x *= 10;
            n2 /= 10;
        }
        if(n2 < 10) return -1;
        long n3 = n;
        long a1 = (n/x)%10;
        long y = 1;
        while(n3%10 <= a1){
            n3 /= 10;
            y *= 10;
        }
        // swap
        long start = n / (x*10);
        long middle = (n / y) % 10;
        long end = (n % x) - (middle - a1) * y; 
        
        //cout << start << " " << middle <<  " "  << end << endl;
        long ans = (start * 10L + middle) * x + reverse(end);
        if(ans > INT_MAX) return -1;
        return ans;
    }
};
