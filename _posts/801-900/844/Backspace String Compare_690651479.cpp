class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=0, j=0;
        for(;i<s.length();i++){
            if(s[i] == '#'){
               j--;
                if(j<0) j=0;
            }else{
                s[j] = s[i];
                j++;
            }
        }
        
        int k=0, l=0;
        for(;k<t.length();k++){
            if(t[k] == '#'){
                l--;
                if(l<0)l=0;
            }else{
                t[l] = t[k];
                l++;
            }
        }
        // cout << s << " " << t << endl;
        if(j!=l) return false;
        
        for(int m=0;m<j;m++){
            if(s[m]!=t[m]) return false;
        }
        
        return true;
    }
};
