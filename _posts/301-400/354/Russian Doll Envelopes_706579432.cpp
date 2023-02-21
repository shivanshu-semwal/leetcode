bool comp(const vector<int> &a, const vector<int> &b){
    if(a[0]==b[0]) return a[1] > b[1];
    return a[0] < b[0]; 
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(), e.end(), comp);
        int n = e.size();
        
        vector<int> v;
        
        for(int i=0;i<n;i++){
            if(v.empty() || v.back() < e[i][1]) v.push_back(e[i][1]);
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), e[i][1]);
            *it = e[i][1];
        }
        
        return v.size();
    }
};
