class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]++;
            } else{
                m[nums[i]] = 1;
            }
        }
        
        vector<pair<int, int>> ans;
        for(auto i:m){
            ans.push_back({i.second, i.first});    
        }
        
        sort(ans.begin(), ans.end(), greater<pair<int, int>>());
        
        
        vector<int> temp;
        for(int i=0;i<k;i++){
            temp.push_back(ans[i].second);
        }
        return temp;   
    }
};
