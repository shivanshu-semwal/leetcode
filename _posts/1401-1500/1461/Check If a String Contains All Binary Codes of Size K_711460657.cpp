class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(k>=n) return false;
        int ans = 0;
        int base = 1;
        for(int i=n-1; i>n-k-1;i--){
            ans = ans + ((s[i]=='0') ? 0 : 1) * base;
            base <<= 1;
        }
        base >>= 1;
        // cout << base << endl;
        long t = (1 << k) - 1;
        // cout << t << endl;
        vector<bool> m(t+1, false);
        
        m[ans] = true;
        // cout << ans << endl;
        for(int i=n-1-k;i>=0;i--){
            ans = (ans>>1) + ((s[i]=='0') ? 0 : 1) * base;
            // cout << ans << endl;
            m[ans] = true;
        }
        
        for(int i=0;i<=t;i++) if(!m[i]) return false;
        return true;
    }
};
