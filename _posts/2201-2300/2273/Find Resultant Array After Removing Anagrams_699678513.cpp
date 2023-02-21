class Solution {
public:
    
    vector<int> getCount(string &s){
        vector<int> c(27, 0);
        for(int i=0;i<s.length();i++){
            c[s[i]-'a']++;
        }
        return c;
    }
    
    bool compare(vector<int> &a, vector<int> &b){
        for(int i=0;i<a.size();i++) if(a[i]!=b[i]) return false;
        return true;
    }
    
    vector<string> removeAnagrams(vector<string>& words) {
        if(words.size() == 0) return vector<string>();
        
        vector<string> ans;
       
        vector<vector<int>> help;
        for(int i=0;i<words.size();i++){
            help.push_back(getCount(words[i]));
        }
        
        ans.push_back(words[0]);
        int j = 0;
        for(int i=0;i<words.size();i++){
            if(compare(help[j], help[i]) == false){
                ans.push_back(words[i]);
                j = i;
            }
        }
        
        return ans;
    }
};
