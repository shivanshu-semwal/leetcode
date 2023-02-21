class Solution {
public:
    
    vector<string> ans;
    
    void permute(vector<vector<char>> &m, string &s, string &a, int i=0){
        if(i==s.length()){
            ans.push_back(a);
            return;
        }
        
        for(int j=0;j < m[s[i] - '0'].size(); j++){
            a.push_back(m[s[i] - '0'][j]);
            permute(m, s, a, i+1);
            a.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits=="") return vector<string>();
        vector<vector<char>> m = {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'},
                                  {'j', 'k', 'l'}, {'m','n','o'}, {'p','q','r','s'}, {'t','u','v'},
                                  {'w', 'x', 'y', 'z'}
                                 };
        string a;
        permute(m, digits, a);
        return ans;
    }
};
