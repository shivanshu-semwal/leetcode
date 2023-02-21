class Solution {
public:
   
    int search(vector<int>& a, int t) {
        int l=0, r=a.size()-1;
        
        while(l<=r){
            int m = l + (r-l)/2;
            if(a[m] == t) return m;
            
            int n;
            if((a[0] <= t) == (a[0] <= a[m]))
                n = a[m];
            else {
                if(t < a[0]) n = INT_MIN;
                else n = INT_MAX;
            }
            cout << n << endl;
            if(t > n){
                cout << "l: " << endl;
                l=m+1;
            } else {
                cout << "r: " << endl;
                r=m-1;
            }
        }
        return -1;
    }
};
