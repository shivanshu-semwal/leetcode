class Solution {
public:
    double Pow(double x, long n){
        if(n==0) return 1.00;
        if(n>0){
            if(n&1) return x * Pow(x, n-1);
            else {
                double temp = Pow(x, n/2);
                return temp*temp;
            }
        } else {
            return Pow(1/x, -n);
        }   
    }
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(x==1) return 1;
        return Pow(x, n);
    }
};
