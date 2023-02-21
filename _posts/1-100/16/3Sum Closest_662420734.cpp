class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int ans = INT_MAX;
        int sum = 0;
        
        for(int i=0;i<n-2;){
            int c = nums[i];
            
            int l = i+1;
            int r = n-1;
            
            // int t = target - c;
            
            while(l < r){
                int a = nums[l], b = nums[r];
                int tt = a + b + c;
                if(tt == target) return target;
                else if(tt < target){
                    while(l <= r && nums[l] == a) l++;
                }
                else{
                    while(r >= l && nums[r] == b) r--; 
                }
                //cout << tt << endl;
                if(ans > abs(target - tt)){
                    ans = abs(target - tt);
                    sum = tt;
                }  
            }
            while(i<n && nums[i] == c) i++;
        }
        
        return sum;
    }
};

/*
1
-4 -1 1 2
- 1 - -4 = 5
- 
*/
