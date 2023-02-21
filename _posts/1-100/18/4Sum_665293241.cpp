class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<=3) return  vector<vector<int>> {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i=0;
        while(i<n-3){
            int a=nums[i];
            for(int j=i+1;j<n-2;){
                int b = nums[j];
                int l = j+1;
                int r = n-1;
                int c, d;
                long sum;
                while(l<r){
                    c=nums[l];
                    d=nums[r];
                    sum = a + 0L + b + c + d;
                    if(sum==target){
                        ans.push_back({a, b, c, d});
                        while(l < r && nums[l]==c) l++;
                        while(r > l && nums[r]==d) r--;
                    } else if(sum < target){
                        while(l < r && nums[l]==c) l++;
                    } else {
                        while(r > l && nums[r]==d) r--;
                    }
                }
                while(j< n-2 &&  nums[j]==b) j++;
            }
            while(i<n && nums[i]==a) i++;
        }
        return ans;
    }
};
