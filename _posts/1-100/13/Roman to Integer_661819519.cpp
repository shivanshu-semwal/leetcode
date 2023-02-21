class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int prev = 0;
        int n =s.length();
        
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        for(int i=0;i<n;i++){
            int c = m[s[i]];
            if(c > prev){
                ans = ans - prev + (c - prev);
            } else {
                ans += c;
            }
            prev = c;
        }
        
        return ans;
    }
};
