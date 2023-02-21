class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        int c1[27];
        int c2[27];
        memset(c1, 0, sizeof c1);
        memset(c2, 0, sizeof c2);
        for(auto i:s) c1[i-'a']++;
        for(auto i:t) c2[i-'a']++;
        
        int ans = 0;
        while(1){
            bool ok = true;
            for(int i=0;i<27;i++) {
                if(c1[i] < c2[i]) {
                    ok = false;
                    return ans;
                    // break;
                }
            }
            for(int i=0;i<27;i++) {
                c1[i] -= c2[i];
            }
            ans++;
        }
        return ans;
    }
};
