class Solution {
public:
    int countVowelStrings(int n) {
        // aeiou   
        vector<int> a(n, 0), e(n, 0), i(n,0) , o(n,0), u(n,0);
        a[0] = 1;
        e[0] = 1;
        i[0] = 1;
        o[0] = 1;
        u[0] = 1;
        
        for(int j=1;j<n;j++){
            a[j] = a[j-1] + e[j-1] + i[j-1] + o[j-1] + u[j-1];
            e[j] = e[j-1] + i[j-1] + o[j-1] + u[j-1];
            i[j] = i[j-1] + o[j-1] + u[j-1];
            o[j] = o[j-1] + u[j-1];
            u[j] = u[j-1];
        }
        
        int ans = a[n-1] + e[n-1] + i[n-1] + o[n-1] + u[n-1];
        return ans;
    }
};
