class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {     
        int n = nums.size();
        
        unordered_map<int, int> m;
        
        for(int i=0;i<n;i++){
            m[nums[i]] = i;
        }
        
        for(int i=0;i<n;i++){
            int search = target - nums[i]; // search
            unordered_map<int, int>::iterator x = m.find(search);
            if(x!=m.end() && m[search] != i){
                return vector<int> {i, m[search]};
            }
        }
        
        return vector<int> {0,0};
    }
};
