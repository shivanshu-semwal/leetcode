class Solution {
public:
    
    unordered_map<int, int> m;
    vector<vector<int>> ans;
    
    void permute(vector<int> t, vector<int> a, int idx=0){
        for(int i=0;i<t.size();i++){
            if(m[t[i]] != 0){
                a[idx] = t[i];
                m[t[i]]--;
                if(idx == a.size() - 1){
                    ans.push_back(a);
                    m[t[i]]++;
                    continue;
                }
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
