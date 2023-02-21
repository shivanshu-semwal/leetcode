class Solution {
public:
    
    int maxScore(vector<int>& p, int k) {
        int n=p.size();
        vector<int> s(n, 0);
        
        s[0] = p[0];
        for(int i=1;i<n;i++) s[i] = s[i-1] + p[i];
        if(k==n) return s[k-1];
        int m=0;
        for(int i=-1;i<k && i<n;i++) {
            cout << i << endl;
            int a = (i==-1) ? 0 : s[i];
            int b = (i==k-1) ? 0 : s[n-1] - s[n - (k-i)]; // error if k==n
            cout << a << " " << b << endl;
            m = max(m, a + b);
        }
        
        return m;  
    }
};
