class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        
        for(int i=0;i<nums2.size();i++) m[nums2[i]] = i;
        
        vector<int> v(nums2.size(), -1);
        stack<pair<int, int>> st;
        
        for(int i=0;i<nums2.size();i++){
            if(st.empty()) st.push({nums2[i], i});
            while(!st.empty() && st.top().first < nums2[i]){
                auto t = st.top();
                st.pop();
                v[t.second] = nums2[i];
            }
            st.push({nums2[i], i});
        }
        
        vector<int> ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i] = v[m[nums1[i]]];
        }
        return ans;
    }
};
