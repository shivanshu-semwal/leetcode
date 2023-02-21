class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(vector<int> &c, int t, vector<int> &a, int i){
        if(t==0){
            ans.push_back(a);
            return;
        }
        if(i<0) return;
        if(c[i] > t){
            solve(c, t, a, i-1);
        }
        else {
            a.push_back(c[i]);
            solve(c, t-c[i], a, i-1);
            a.pop_back();
            
            int temp = c[i];
            while(i>-1 && temp==c[i]) i--;
            solve(c, t, a, i);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(), c.end());
        vector<int> a;
        solve(c, t, a, c.size() -1);
        return ans;
    }
};
