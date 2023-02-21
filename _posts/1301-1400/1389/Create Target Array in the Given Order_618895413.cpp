class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<bool> isSet(n, false);
        for(int i=0;i<n;i++){
            if(!isSet[index[i]]){
                isSet[index[i]] = true;
            }
            else {
                for(int j=0;j<i;j++){
                    if(index[j]>=index[i]){
                        index[j]++;
                        isSet[index[j]] = true;
                    }
                }
            }
        }
        
        vector<int> target(n);
        for(int i=0;i<n;i++){
            target[index[i]] = nums[i];
        }
        return target;
    }
};
