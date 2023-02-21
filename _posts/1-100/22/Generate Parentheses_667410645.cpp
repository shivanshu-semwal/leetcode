class Solution {
public:
    map<int, vector<string>> m;
    
    Solution(){
        m[0] = vector<string> {""};
        m[1] = vector<string> {"()"};
    }
    
    vector<string> generateParenthesis(int n) {
        if(m.find(n)!=m.end()) return m[n];
        vector<string> ans;
        for(int i=0;i<n;i++){
            vector<string> a = generateParenthesis(i);
            vector<string> b = generateParenthesis(n-1-i);
            for(auto i:a){ for(auto j:b) {
                ans.push_back("(" + i + ")" + j);
            } }
        }
        m[n] = ans;
        return ans;
    }
};
