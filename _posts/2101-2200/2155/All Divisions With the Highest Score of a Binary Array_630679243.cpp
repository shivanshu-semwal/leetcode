class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> count0(n+1);
        vector<int> count1(n+1);  
        
        count0[0] = 0;
        for(int i=1;i<n+1;i++){
            if(nums[i-1] == 0) count0[i] = count0[i-1] + 1; 
            else count0[i] = count0[i-1];
        }
        
        
        count1[n] = 0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==1) count1[i] = count1[i+1] + 1;
            else count1[i] = count1[i+1];
        }
        
        int max = count0[0] + count1[0];
        for(int i=0;i<n+1;i++){
            count0[i] = count0[i] + count1[i];
            if(count0[i] > max){
                max = count0[i];
            }
        }
        
        vector<int> sol;
        for(int i=0;i<n+1;i++){
            if(count0[i]==max) sol.push_back(i);
        }
        return sol;
    }
};
