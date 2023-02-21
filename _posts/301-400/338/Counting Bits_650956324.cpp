class Solution {
public:
    int countbits(int x){
        if(x<=0) return 0;
        else return ((x&1)?1:0) + countbits(x>>1); 
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=0;i<=n;i++) ans[i] = countbits(i);
        return ans;
    }
};
