class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m;
        m.reserve(100000);
        for(int i=0;i<nums.size();i++){
            int search = target - nums[i]; // search
            
            if(m.find(search) != m.end()){
                // element found
                return vector<int> {i, m[search]};
            }
            m[nums[i]] = i; 
        }
        
        
        return vector<int> {0,0};
    }
};
