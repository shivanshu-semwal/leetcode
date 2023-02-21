class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        unordered_map<int, int> m;
        
        int count=0;
        int prev = INT_MIN;
        for(int i=0;i<temp.size();i++){
            if(temp[i] != prev) m[temp[i]] = count;
            count++;
            prev = temp[i];
        }
        
        vector<int> vv(temp.size());
        for(int i=0;i<vv.size();i++){
            vv[i] = m[nums[i]];
        }
        
        return vv;
    }
};
