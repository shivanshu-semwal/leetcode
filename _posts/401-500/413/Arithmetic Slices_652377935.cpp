class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        
        
        vector<int> ans(n-1, 0);
        for(int i=0;i<n - 1;i++){
            ans[i] = nums[i+1] - nums[i];    
        }
        
        for(int i=0;i<ans.size();i++) cout << ans[i] << " " ;
        cout << endl;
        
        vector<int> ans2;
        
        int prev = ans[0];
        int count = 1;
        for(int i=1;i<ans.size();i++){
            if(prev == ans[i]){
                count++;
            }
            else {
                ans2.push_back(count);
                prev = ans[i];
                count = 1;
            }
        }
        ans2.push_back(count);
        
        for(int i=0;i<ans2.size();i++) cout << ans2[i] << " " ;
        cout << endl;
        
        count = 0;
        for(int i=0;i<ans2.size();i++){
            if(ans2[i]>1){
                int x = ans2[i] + 1;
                count += (x-1)*(x-2)/2;
                cout << count << endl;
            }
        }
        
        return count;
    }
};
