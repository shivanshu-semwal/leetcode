class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] % 2 != 0){
                bool flag = false;
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]%2 == 0){
                        //swap
                        flag = true;
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
        }
        return nums;   
    }
};
