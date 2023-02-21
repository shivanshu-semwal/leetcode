class Solution {
public:
    
    unordered_map<int, int> m;
    vector<vector<int>> ans;
    
    void permute(vector<int> t, vector<int> a, int idx=0){
        if(idx == a.size()){
            ans.push_back(a);
            return;
        }
        for(int i=0;i<t.size();i++){
            if(m[t[i]] != 0){
                a[idx] = t[i];
                m[t[i]]--;
                permute(t, a, idx + 1);
                m[t[i]]++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> t; t.reserve(nums.size());
        for(auto i:nums){
            if(m.find(i) == m.end()){
                t.push_back(i);
                m[i] = 1;
            } else {
                m[i]++;
            }
        }
        
        vector<int> a(nums.size(), 0);
        permute(t, a);
        return ans;
    }
};
