class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        // st.push("/");
        
        int n = path.length();
        int start = 1;
        for(int i=1;i<n;i++){
            if(path[i] == '/'){
                if(i==start){
                    start = i+1;
                    continue;
                }
                string temp = path.substr(start, i-start);
                cout << temp << endl;
                if(temp == ".."){
                    if(!st.empty()) st.pop();
                    start = i+1;
                } 
                else if(temp==".") {
                    start = i+1;
                    continue;
                }
                else {
                    st.push(temp);
                    start = i+1;
                }
            }
        }
        if(start < n){
            string temp = path.substr(start, n-start);
            if(temp == ".."){
                if(!st.empty()) st.pop();
            } else if(temp!=".") st.push(temp);
        }
        
        if(st.empty()) return "/";
        
        // while(!st.empty()) {
        //     cout << "[" << st.top() << endl;
        //     st.pop();
        // }
        // return "";
        
        string ans = "/" + st.top();
        st.pop();
        
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
