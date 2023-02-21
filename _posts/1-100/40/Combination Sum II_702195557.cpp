class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& c,int idx, int target, vector<int> &a){
        if(idx == c.size()){
            if(target==0) ans.push_back(a);
            return;
        }
        if(target < c[idx]){
            if(target == 0) ans.push_back(a);
            return;
        }
        
        a.push_back(c[idx]);
        solve(c, idx+1, target-c[idx], a);
        a.pop_back();
        
        int temp = c[idx];
        while(idx < c.size() && c[idx] == temp) idx++;
        
        solve(c, idx, target, a);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector<int> a;
        solve(c, 0, target, a);
        return ans;
    }
};
