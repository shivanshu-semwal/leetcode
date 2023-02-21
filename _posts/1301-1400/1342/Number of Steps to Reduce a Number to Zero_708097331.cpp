class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return 0;
        if(num==1) return 1;
        
        int ans = 0;
        while(num){
            if(num&1) ans += 2;
            else {ans+=1;}
            
            num = num >> 1;
        }
        return ans-1;
    }
};
