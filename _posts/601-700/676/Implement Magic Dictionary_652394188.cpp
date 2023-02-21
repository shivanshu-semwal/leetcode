class trie{
public:
    trie *child[26];
    bool isword;
    trie(){
        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
        isword = false;
    }
};

class MagicDictionary {
public:
    trie *root;
    
    MagicDictionary() {
        root = new trie();       
    }
    void insert(string s){
        trie *t = root;
        for(int i=0;i<s.length();i++){
            if(t->child[s[i] - 'a'] == nullptr){
                t->child[s[i] - 'a'] = new trie();
            }
            t = t->child[s[i] - 'a'];
        }
        t->isword = true;
    }
    void buildDict(vector<string> dic) {
        for(auto i: dic){
            insert(i);
        }
    }
    
    bool findd(string &s, trie *t, int i){
        while(i < s.length()){
            if(t->child[s[i]-'a'] == nullptr) return false;
            t = t->child[s[i]-'a'];
            i++;
        }
        return t->isword;
    }
    
    bool search(string s) {
        trie *start = root;
        for(int i=0;i<s.length(); i++){
            for(char c = 0; c < 26;c++){
                if(c==s[i]-'a') continue;
                if(start->child[c] && findd(s, start->child[c], i+1))
                    return true;
            }
            if(start->child[s[i]-'a'] == nullptr) return false;
            start = start->child[s[i] - 'a'];
        }
        return false;
    }
};
