class Solution {
public:
    bool isUgly(int n) {
        if(n==0) return false;
        bool flag = true;
        while(flag){
            flag = false;
            if(n % 5 == 0) { n = n/5; flag = true; }
            if(n % 3 == 0) { n = n/3; flag = true; }
            if(n % 2 == 0) { n = n/2; flag = true; }
        }
        return n==1;
    }
};
