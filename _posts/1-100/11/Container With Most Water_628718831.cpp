class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int m = min(h[0], h[n-1]) * (n-1 - 0);
        int l=0, r = n-1;
        while(l<r){
            int water = min(h[l], h[r]) * (r-l);
            m = max(m, water);
            if(h[l] < h[r]){
                l++;
            } else{
                r--;
            }
        }
        return m;
    }
};
