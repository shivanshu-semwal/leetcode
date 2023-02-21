class Solution {
public:
    
    unordered_map<int, int> m;
    vector<vector<int>> ans;
    int n;
    
    void permute(vector<int> a, vector<int> &temp){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<a.size();i++){
            if(m[a[i]] != 0){
                temp.push_back(a[i]);
                m[a[i]]--;
                permute(a, temp);
                m[a[i]]++;
                temp.pop_back();
            }
        }
    }
        
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<int> a;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]) == m.end()) {
                a.push_back(nums[i]);
                m[nums[i]] = 1;
            }
            else m[nums[i]]++;
        }
        
        vector<int> t;
        permute(a, t);
        
        return ans;
    }
};
