class Solution {
public:
    typedef struct trie{
        unordered_map<char, struct trie *> mp;
        bool e;
        trie() {
            e = false;
        }
    } trie;
    trie *t;
    void insert(string s) {
        trie *tm = t;
        for(int i=0;i<s.size();i++) {
            if(tm->mp.find(s[i]) == tm->mp.end()) {
                tm->mp[s[i]] = new trie();
            }
            tm = tm->mp[s[i]];
        }
        tm->e = true;
    }
    int solve(string s, int i, int c, vector<int> &dp) {
        if (i == s.size())
            return c >= 2;
        if(dp[i] != -1) return dp[i];
        trie *ptr = t;
        for (int j = i; j < s.size(); j++) {
            if (ptr->mp.find(s[j]) == ptr->mp.end()) 
                return dp[i] = false;
            ptr = ptr->mp[s[j]];
            
            if (ptr->e)
                if (solve(s, j + 1, c + 1, dp))
                    return dp[i] = true;
        }
        
        return dp[i] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& v) {
        t = new trie();
        for(auto i:v) {
            insert(i);
        }
        vector<string> res;
        for(auto s:v) {
            int n = s.size();
            vector<int> dp(n+1, -1);
            if(solve(s,0,0,dp)) 
                res.push_back(s);
        } 
        return res;
    }
};
