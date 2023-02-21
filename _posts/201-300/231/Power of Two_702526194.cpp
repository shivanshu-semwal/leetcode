class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return 0;
        bool flag = false;
        while(n){
            if(n&1) {
                if(flag) return false;
                else flag = true;
            }
            n >>= 1;
        }
        return true;
    }
};
