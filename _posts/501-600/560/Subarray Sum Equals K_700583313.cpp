class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n+1, 0);
        
        unordered_map<int, int> c;
        
        int ans = 0;
        s[0] = 0;
        c[0] = 1;
        
        for(int i=0;i<n;i++){
            s[i+1] = s[i] + nums[i];
            int t = s[i+1] - k;
            if(c.find(t) != c.end()){
                ans = ans + c[t];
            }
            // cout << s[i+1] << endl;
            if(c.find(s[i+1]) == c.end()) c[s[i+1]] = 1;
            else c[s[i+1]]++;
        }
        
        return ans;
    }
};
