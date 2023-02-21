class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sol(1<<n, vector<int> (0, 0));
        
        sol[0] = vector<int> (0,0);
        
        for(int i=1;i < 1<<n; i++){
            //bitset<10> temp(i);
            vector<int> t;
            for(int j=0;j<n;j++){
                if(i & (1<<j)) t.push_back(nums[j]);
            }
            sol[i] = t;
        }
        return sol;
    }
};
