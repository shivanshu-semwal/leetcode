class Solution {
public:
    
    vector<vector<int>> ans;
    
    
    void solve(vector<int>& c, vector<int> &a, int t, int idx){
        
        // cout << idx << endl;
        
        if(t==0){
            ans.push_back(a);
            return;
            // return true;
        }
        if(idx < 0){
            return;
            // return false;
        }
        
        if(c[idx] > t){
            solve(c, a, t, idx-1);
        }
        else {
            a.push_back(c[idx]);
            solve(c, a, t - c[idx], idx);
            a.pop_back();
            solve(c, a, t, idx-1);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t){
        sort(c.begin(), c.end());
        vector<int> a;
        solve(c, a, t, c.size() - 1);
        return ans;
    }
};
