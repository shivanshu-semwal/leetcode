class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a=0, b=0;
        while(a<nums.size()){
            if(nums[a]!=0){
                swap(nums[a], nums[b]);
                b++;
            }
            
            a++;
        }
    }
};
