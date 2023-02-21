class Solution {
public:
    int kthFactor(int n, int k) {

        float root = sqrt(n);
        
        vector<int> ans;
        
        for (int i=1; i<root; i++) {
            if (n % i == 0){
                if(--k == 0) return i;
                else{
                    if(i*i != n) ans.push_back(n/i);
                }
                cout << ans.back() << " ";
            }
        }

        for (int i=root; i>0; i--) {
            if (n % i == 0 && --k == 0) return n/i;
        }

        return -1;

    }
};
