class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), k=0;
        for(int b=n/2;b>=1;b/=2) while(k+b<n && nums[k+b]<=target) k+=b;
        return (nums[k] == target)?k:-1;
    }
};
