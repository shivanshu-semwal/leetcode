class Solution {
public:
    vector<vector<int>> ans;
    
    
    void solve(int s, int n, int k, vector<int> &t){
        // cout << s << " " << n << " " << k << endl;
        if(k==0 && n==0) ans.push_back(t);
        
        if(k==0) return;
        if(n==0) return;
        
        for(int i=s;i<=n && i<=9;i++){
            t.push_back(i);
            solve(i+1, n-i, k-1, t);
            t.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        // 2 <= k <= 9
        // 1 <= n <= 60
        
        if(k>n) return  vector<vector<int>>();
        
        vector<int> t;
        solve(1, n, k, t);
        
        return ans;
    }
};
