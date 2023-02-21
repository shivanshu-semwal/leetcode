class Solution {
public:
    
    vector<string> ans;
    int n;
    
    
    void solve(vector<char> &a, int px, int open, int close){
        if(px == a.size()){
            ans.push_back( string(a.begin(), a.end()) );
            return;
        }
        
        if(open < n/2){
            a[px] = '(';
            solve(a, px + 1, open+1, close);
        }
        
        if(open > close){
            a[px] = ')';
            solve(a, px + 1, open, close + 1);
        }
    }
    
    vector<string> generateParenthesis(int nn) {
        
        n = nn*2;
        
        vector<char> a(n, 'a');
        
        solve(a, 0, 0, 0);
        
        return ans;
    }
};
