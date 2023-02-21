class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c=='(' || c == '{' || c == '['){
                ss.push(c);   
            } else {
                if(ss.empty()) return false;
                char cc = ss.top();
                if(c==')' && cc == '(') ss.pop();
                else if (c==']' && cc == '[') ss.pop();
                else if (c=='}' && cc == '{') ss.pop();
                else return false;
            }
        }
        if(ss.empty()) return true;
        else return false;
    }
};
