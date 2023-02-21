class Solution {
public:
    int findLucky(vector<int>& arr) {
        int a[501] = {0};
        
        int m=0;
        for(auto i:arr){
            a[i]++;
            m = max(m, i);
        }
        
        for(int i=m;i>0;i--){
            if(a[i] == i) return i;
        }
        
        return -1;
    }
};
