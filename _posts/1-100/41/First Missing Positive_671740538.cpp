class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;){
            if(nums[i] > 0 && nums[i] <= n && nums[i] - 1 != i){
                if(nums[nums[i] - 1] == nums[i]){
                    i++;
                    continue;
                }
                int temp = nums[i];
                // cout << "swap " << temp << " " << nums[temp -1] << endl;
                nums[i] = nums[temp - 1];
                nums[temp - 1] = temp;
            } else {
                i++;
            }
            // for(auto i:nums) cout << i << " ";
            // cout << endl;
        }

        // for(auto i:nums) cout << i << " ";
        // cout << endl;
        
        for(int  i=0;i<n;i++){
            if(nums[i] != i+1) return i+1;
        }
        
        return n+1;
    }
};
