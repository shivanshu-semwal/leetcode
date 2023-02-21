class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=0, a1=0;
        int b=0, b1=1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==a1) a++;
            else if(nums[i]==b1) b++;
            else if(a==0){ a1 = nums[i]; a++; }
            else if(b==0){ b1 = nums[i]; b++; }
            else { a--; b--; }
        }
        a=0;
        b=0;
        for(int i=0;i<n;i++){
            if(nums[i]==a1) a++;
            else if(nums[i]==b1) b++;
        }
        vector<int> temp;
        if(a > n/3) temp.push_back(a1);
        if(b > n/3) temp.push_back(b1);
        return temp;
    }
};
