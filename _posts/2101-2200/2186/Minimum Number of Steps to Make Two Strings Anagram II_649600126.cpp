class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> ss(27, 0);
        for(int i=0;i<s.length();i++){
            ss[s[i]-'a']++;
        }
        vector<int> tt(27, 0);
        for(int i=0;i<t.length();i++){
            tt[t[i]-'a']++;
        }
        int ans = 0;
        for(int i=0;i<ss.size();i++){
            ans += abs(ss[i] - tt[i]);
        }
        return ans;
    }
};
