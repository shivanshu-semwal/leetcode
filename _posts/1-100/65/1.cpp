class Solution {
public:
    bool isNumber(string s) {
        if(s == "") return false;
        bool dec=false;
        
        int n=s.length();
        int i=0;
        
        if(s[i]=='+' || s[i] == '-') i++;
        if(i==n) return false;
        
        while(i < n && '0' <= s[i] && s[i] <= '9'){
            dec = true;
            i++;
        }
        
        if(i==n) return true;
        
        if(s[i]=='.'){
            i++;
            while(i < n && '0' <= s[i] && s[i] <= '9'){
                dec = true;
                i++;
            }
            if(dec == false) return false;
            if(i==n) return true;
        }
        
        if(s[i]=='e' || s[i] == 'E'){
            i++;
            if(dec == false) return false;
            if(i==n) return false;
            if(s[i]=='+' || s[i] == '-') i++;
            if(i==n) return false;
            while(i < n && '0' <= s[i] && s[i] <= '9') i++;
            if(i==n) return true;
        }
        return false;
    }
};