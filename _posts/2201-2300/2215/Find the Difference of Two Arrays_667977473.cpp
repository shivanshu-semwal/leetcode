class Solution {
public:
    unordered_map<int, bool> n1;
    unordered_map<int, bool> n2;
    
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            if(n1.find(nums1[i]) != n1.end()){
                nums1[i] = INT_MAX;
            } else {
                n1[nums1[i]] = true;
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(n2.find(nums2[i]) != n2.end()){
                nums2[i] = INT_MAX;
            } else {
                n2[nums2[i]] = true;
            }
        }
        vector<vector<int>> a = {{},{}};
        for(auto i:nums1){
            if(i==INT_MAX) continue;
            if(n2.find(i)==n2.end()) a[0].push_back(i);       
        }
        for(auto i:nums2){
             if(i==INT_MAX) continue;
             if(n1.find(i)==n1.end()) a[1].push_back(i);
        }
        return a;
    }
};
