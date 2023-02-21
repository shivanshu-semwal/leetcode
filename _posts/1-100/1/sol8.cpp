class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        m.reserve(10000);
        for(int i=0;i<nums.size();i++){
            if(m.find(target - nums[i]) != m.end()){
                // element found
                return vector<int> {i, m[target - nums[i]]};
            }
            m[nums[i]] = i; 
        }       
        return vector<int> {0,0};
    }
};
