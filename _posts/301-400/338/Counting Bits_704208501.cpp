class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> a(n+1, 0);
        a[0] = 0;
        int p2 = 1;
        for(int i=1;i<=n;i++){
            if(p2 == i){
                a[i] = 1;
                p2 *= 2;
            } else {
                a[i] = 1 + a[i-(p2/2)];                
            }
            // cout << a[i] << endl;
        }
        return a;
    }
};
