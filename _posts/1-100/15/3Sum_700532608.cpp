class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());        
        vector<vector<int>> ans;
        short n = nums.size();        
        
        for(short i=0;i<n-2;){
            int a = nums[i];
            short l=i+1;
            short r=n-1;

            while(l<r){
                int sum = nums[l] + nums[r];
                if(sum == -a){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int t = nums[l];
                    while(l<r && nums[l]==t)l++;
                    t = nums[r];
                    while(l<r && nums[r]==t)r--;
                } else if(sum < -a){
                    l++;
                } else {
                    r--;
                }
            }
            while(i<n-2 && nums[i] == a) i++;
        }
        
        return ans;
    }
};
