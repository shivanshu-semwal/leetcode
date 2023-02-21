class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ch;        
        int m=0;
        for(int r=0, l=0;r<s.length();r++){
            int val = s[r];
            if(ch.find(val) == ch.end()){
                // not found
                ch[val] = r;
            } else {
                // found
                int len = ch[val];
                for(int j=l;j<=len;j++){
                    ch.erase(s[j]);
                }
                l = len + 1;
                ch[val] = r;
            }
            val = r - l + 1;
            //cout << r << " " << l << " "<< val << "\n";
            if(val > m) m = val;
        }
        
        return m;
    }
};
