class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<char> ans;
        for(int i=0;i<strs[0].length();i++){
            bool flag = true;
            for(int j=1;j<strs.size();j++){
                if(i >= strs[j].length() || strs[j][i] != strs[0][i]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(strs[0][i]);
            else break;
        }
        return string(ans.begin(), ans.end());
    }
};
