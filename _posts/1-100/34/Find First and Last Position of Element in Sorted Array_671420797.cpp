class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int n = a.size();
        int l, r;
        
        // left most
        l = 0, r = n-1;
        int aa = -1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(a[m]>t) r = m - 1;
            else if(a[m]<t) l = m + 1;
            else{
                aa = m;
                r = m-1;
            }
        }
        
        // right most
        l = 0, r = n-1;
        int b = -1;
        if(aa!=-1){
            while(l<=r){
                int m = l + (r-l)/2;
                if(a[m]>t) r = m - 1;
                else if(a[m]<t) l = m + 1;
                else{
                    b = m;
                    l = m+1;
                }
            }
        }
        
        return vector<int> {aa, b};
    }
};
