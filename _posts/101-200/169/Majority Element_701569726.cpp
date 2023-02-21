class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a=nums[0];
        int ac = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == a) ac++;
            else ac--;
            
            if(ac==0){
                a=nums[i]; 
                ac = 1;
            }
        }
        
        return a;
    }
};
