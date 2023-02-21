class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-1;
        while(i>0 && nums[i-1] >= nums[i]) i--; // find a position where first elemetmt is greter
        if(i==0){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = nums.size()-1;
        while(j>=i){
            if(nums[i-1] < nums[j]){
                swap(nums[i-1], nums[j]);
                break;
            }
            j--;
        }
        reverse(nums.begin() + i, nums.end());
    }
};


/*
12345
12354
12435
12453
12534

12543

13245
13254

i-1...i.i+1
    <  >    >  >  >
    

*/

