class Solution {
public:
    int numRescueBoats(vector<int>& p, int lim) {
        int n = p.size();
        if(n==1) return 1;
        sort(p.begin(), p.end());
        
        int c = 0;
        
        int l = 0;
        int r = n-1;
        
        while(l<r){
            if(p[l]+p[r]<=lim){
                c++;
                l++;
                r--;
            } else {
                c++;
                r--;
            }
        }
        
        if(l==r) c++;
        
        return c;
    }
};
