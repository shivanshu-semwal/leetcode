class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i=0;i<n-3;){
            
            int a=nums[i];
            int target1 = target - nums[i];
            
            for(int j=i+1;j<n-2;){
                
                int b = nums[j];
                int target2 = target1 - nums[j];
                
                int l = j+1;
                int r = n-1;
                
                while(l<r){
                    int sum = nums[l] + nums[r];
                    if(sum < target2) l++;
                    else if(sum > target2) r--;
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        ans.push_back(temp);
                        while(l<r && nums[l] == temp[2]) l++;
                        while(l<r && nums[r] == temp[3]) r--;
                    }
                }
                while(j<n-2 && nums[j] == b) j++;
            }
            while(i<n-3 && nums[i] == a) i++;
        }
        return ans;
    }
};
