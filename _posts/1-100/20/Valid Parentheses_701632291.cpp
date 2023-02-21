class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &i:s){
            char x = st.empty() ? '*' : st.top();
            if(i==')') if(x =='(') st.pop(); else return false;
            else if(i==']') if(x == '[') st.pop(); else return false;
            else if(i=='}') if(x == '{') st.pop(); else return false;
            else st.push(i);
        }
        if(st.empty()) return true;
        else return false;
    }
};
