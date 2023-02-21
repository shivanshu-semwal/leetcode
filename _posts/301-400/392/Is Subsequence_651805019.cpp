class Solution {
public:
    bool isSubsequence(string t, string s) {
        int i, j;
        for(i=0,j=0;i<s.length();i++){
            if(s[i]==t[j]){
                j++;
            }
            if(j >= t.length()) break;
        }
        if(j>= t.length()) return true;
        return false;
    }
};
