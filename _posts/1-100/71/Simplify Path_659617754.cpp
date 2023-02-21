class Solution {
public:
    string simplifyPath(string p) {
        string ans;
        
        int n = p.length();
        
        // remove double slash
        vector<char> temp;
        temp.push_back(p[0]);
        for(int i=1;i<n;i++){
            if(p[i] == '/' && p[i-1]=='/') continue;
            else temp.push_back(p[i]);
        }
        ans = string(temp.begin(), temp.end());
        
        //cout << p << endl;
        //cout << ans << endl;
        
        stack<string> dir;
        int start = 1;
        string t;
        for(int i=1;i<ans.length();i++){
            if(ans[i]=='/'){
                t = ans.substr(start, i-start);
                start = i+1;
                //cout << "@" << t << endl;
                if(t=="..") {
                    if(!dir.empty()) dir.pop();
                }
                else if(t!=".") dir.push(t);
            }
        }
        //cout << start << " " << ans.length() << " " << ans << " " << endl;
        if(start != ans.length())
        {
            t = ans.substr(start, ans.length() - start);
            //cout << "*" << t << endl;
            if(t=="..") {
                if(!dir.empty()) dir.pop();
            }   
            else if(t!=".") dir.push(t);
        }
        
        string a = "";
        while(!dir.empty()){
            //cout << "--" << a << endl;
            a = "/" + dir.top() + a; dir.pop();
        }
        return (a=="")? "/": a;   
    }
};
