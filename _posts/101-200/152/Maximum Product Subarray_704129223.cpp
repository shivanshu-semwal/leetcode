class Solution {
public:
    int maxProduct(vector<int>& a) {
        int ma=1;
        int mi=1;
        
        int n = a.size();
        int ans = *max_element(a.begin(), a.end());
        
        for(int i=0;i<n;i++){
            if(a[i] == 0) { 
                mi = 1; ma = 1;
                continue;
            }
            int t = ma;
            ma = max(ma * a[i], max(mi * a[i], a[i]));
            mi = min(mi * a[i], min(t * a[i], a[i]));
            
            ans = max(ans, ma);
        }

        return ans;
    }
};
