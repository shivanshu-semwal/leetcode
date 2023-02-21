class Solution {
public:
    map<int, bool> m;
    
    bool isHappy(int n) {
        while(n!=1){
            int n1=0;
            while(n){
                int d = n%10; d*=d;
                n1 += d;
                n /= 10;
            }
            n = n1;
            if(m.find(n) != m.end()) return false;
            else m[n] = true;
        }
        
        return true;
    }
};
