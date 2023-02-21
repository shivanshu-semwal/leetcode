class Solution {
public:
    
    bool search(vector<int>& a, int t) {
        int n = a.size();
        if(n==0) return false;
        
        int l = 0;
        int r = n-1;
        
        while(l<=r){
            while(l < r && a[l]==a[l+1]) l++;
            while(l < r && a[r-1]==a[r]) r--;
            
            int m = l + ((r-l)>>1);
            
            if(a[m]==t) return true;
            
            if(a[l] <= a[m]){
                if(a[l] <= t && t < a[m]) r = m - 1;
                else l = m + 1;
            } else{
                if(a[m] < t && t <= a[r]) l = m + 1;
                else r = m - 1;
            }   
        }
        return false;
    }
};
