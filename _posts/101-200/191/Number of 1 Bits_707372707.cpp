class Solution {
public:
    int hammingWeight(uint32_t n) {
    
        
        // 0101 - 5
        // 0100 - 5-1
        int c=0;
        while(n){
            if(n&1) c++;
            n >>=1;
        }
        return c;
    }
};
