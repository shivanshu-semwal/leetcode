class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> f;
        for(int i=1;i<=n;i++){
            if(n%i==0) f.push_back(i);
            if(f.size() == k) return f.back();
        }
        return -1;
    }
};
