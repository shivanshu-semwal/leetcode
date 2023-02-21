class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        int ss=0;
        int n=s.length(), i=0;
        while(ss<n && s[ss]==' ') ss++;
        string ans = "";
        i = ss+1;
        while(i<n){
            if(s[i]==' '){
                ans = s.substr(ss, i-ss+1) + ans;
                while(i<n && s[i]==' ') i++;
                ss = i;
                i++;
            }
            else i++;
        }
        return ans.substr(0, ans.length()-1);
    }
};
