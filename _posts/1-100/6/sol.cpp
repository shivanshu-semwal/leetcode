class Solution {
public:
    string convert(string s, int n) {
        
        if(s.length()==1 || s.length()==2 || n==1) return s;
        
        vector<vector<char>> t(n, vector<char>());
        
        int i=0, j=0, k=1;
        while(i<s.length()){
            t[j].push_back(s[i]);
            j+=k;
            i++;
            
            if(j==n){
                k = -k;
                j -= 2;
            }
            
            if(j==-1){
                k=-k;
                j+=2;
            }
        }
        
        string ans = "";
        for(auto i: t){
            ans += string(i.begin(), i.end());
        }
        
        return ans;
    }
};
