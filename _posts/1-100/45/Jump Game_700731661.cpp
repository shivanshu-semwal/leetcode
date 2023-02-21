bool arr[10000];

class Solution {
public:

    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int n = nums.size();
        fill_n(arr, 10000, false);
        arr[n-1] = true;
        for(int i=n-2;i>=0;i--){
            for(int j=1;!arr[i] && j<=nums[i] && i+j < n;j++){
                arr[i] = arr[i+j];
            }
        }
        
        return arr[0];
    }
};
