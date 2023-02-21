class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        int c = 0;
        for(int i=0, j=0;i<nums.size();i++){
            if(j%2==0){
                if(i+1 < n && nums[i]==nums[i+1]) {
                    c++;
                    continue;
                }
            }
            j++;
        }
        if((n-c) % 2 != 0) c++;
        return c;
    }
};
