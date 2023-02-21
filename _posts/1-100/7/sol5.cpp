class Solution {
public:
    int reverse(int x) {
        int a = 0;
        
        while(x){
            int t=x%10;
            if(a>INT_MAX/10) return 0;
            if(a<INT_MIN/10) return 0;
            if(a==INT_MAX/10 && t > INT_MAX%10) return 0;
            if(a==INT_MIN/10 && t < INT_MIN%10) return 0;
            a = a*10 + t;
            x /= 10;
        }
        
        return a;
    }
};
