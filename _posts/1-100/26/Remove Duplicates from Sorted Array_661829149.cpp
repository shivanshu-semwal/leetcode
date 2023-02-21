class Solution {
public:
    int removeDuplicates(vector<int>& nums) {    
        int j=0;
        int prev = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == prev){
                continue;
            } else{
                prev=nums[i];
                nums[j++] = prev;
            }
        }
        return j;
    }
};
