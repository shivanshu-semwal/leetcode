class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        double x = log10(n) /  log10(3);        
        double y = x - floor(x);
        if(y==0){
            return true;
        } else{
            return false;
        }
    }
};
