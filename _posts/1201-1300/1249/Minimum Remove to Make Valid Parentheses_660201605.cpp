class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        vector<char> ans;
        stack<int> p;
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i] != ')' && s[i] != '('){
                ans.push_back(s[i]); j++;
            }
            else if(s[i]=='('){
                ans.push_back('('); 
                p.push(j++);
            } else {
                if(!p.empty()){
                    //cout << "*" << s[i] << endl;
                    p.pop();
                    ans.push_back(')'); j++;
                }
            }
        }
        while(!p.empty()){
            ans[p.top()] = 15;
            p.pop();
        }
        //cout << string(ans.begin(), ans.end()) << endl;
        
        vector<char> f;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=15){
                f.push_back(ans[i]);
            }
        }
        return string(f.begin(), f.end());
    }
};
