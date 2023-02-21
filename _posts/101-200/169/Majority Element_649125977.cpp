class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=nums[0];
        int vot=1;
        for(int i=1;i<nums.size();i++){
            if(vot==0){
                ele = nums[i];
                vot++;
            }
            else if(nums[i] == ele){
                vot++;
            }else{
                vot--;
            }
        }
        return ele;
    }
};
