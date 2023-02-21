class Solution {
public:
    int search(vector<int>& a, int t) {
        int l=0;
        int r=a.size() - 1;
        
        while(l<=r){
            int m = l + ((r-l)>>1);
            
            // for(int i=0;i<a.size();i++){
            //     if(i==l || i == r || i == m) cout << "[" << a[i] << "] ";
            //     else cout << a[i] << " ";
            // }
            // cout << endl;
       
            if(a[m] == t) return m;
            
            if(a[l] <= a[m]){
                if(a[l] <= t && t < a[m]) r = m - 1;
                else l = m + 1;
            } else {
                if(a[m] < t && t <= a[r]) l = m + 1;
                else r = m - 1;
            }
        }
        
        return -1;
    }
};
