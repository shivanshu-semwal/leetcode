class Solution {
public:
    int brokenCalc(int s, int t) {
        if(t<=s) return s-t;
        
        
        int c = 0;
        
        int tt = t;
        while(tt > s){
            if(tt&1){
                tt = tt + 1;
                c++;
            } else{
                tt = tt / 2;
                c++;
            }
        }
        
        c += s - tt;
        
        return c;
    }
};

