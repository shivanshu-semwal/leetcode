class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans =0;
        int n = words.size();
        for(int i=0;i<n;i++){
            if(words[i].length() < pref.length()) continue;
            bool flag = true;
            for(int j=0;j<pref.length();j++){
                if(words[i][j] != pref[j]){
                    flag = false;
                    break;
                }   
            }
            if(flag) ans++;
        }
        return ans;
    }
};
