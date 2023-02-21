stack<pair<char, short>> *st;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        st = new stack<pair<char, short>>();
        
        (*st).push({s[0], 1});
        
        for(int i=1;i<s.length();i++){
            if((*st).empty()){
                (*st).push({s[i], 1});   
            }
            else if(s[i]==(*st).top().first){
                (*st).push({s[i], (*st).top().second+1});
            } else {
                (*st).push({s[i], 1});
            }
            if((*st).top().second == k){
                for(int ii=0;ii<k;ii++) (*st).pop();
            }
        }
        
        string ans = "";
        while(!(*st).empty()){
            ans.push_back((*st).top().first);
            (*st).pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
