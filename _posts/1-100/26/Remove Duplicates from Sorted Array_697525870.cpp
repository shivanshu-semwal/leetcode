class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = INT_MAX;
        int j=0;
        for(int i=0;i<nums.size();i++){
            int temp = nums[i];
            if(nums[i] != prev){
                swap(nums[i], nums[j]);
                j++;
            }
            prev = temp;
        }
        return j;
    }
};
