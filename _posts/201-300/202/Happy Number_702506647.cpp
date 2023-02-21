class Solution {
public:
    int getNext(int n){
        int ans = 0;
        while(n){
            int t = n%10;
            t *= t;
            ans += t;
            n /= 10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        int a = n;
        int b = getNext(n);
        while(a!=1){
            if(a==b) return false;
            a = getNext(a);
            b = getNext(getNext(b));
        }
        return true;
    }
};
