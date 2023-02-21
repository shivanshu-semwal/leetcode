class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        sort(i.begin(), i.end());
        vector<vector<int>> ans;
        
        for(int k=0;k<i.size();){
            int s = i[k][0];
            int e = i[k][1];
            k++;
            while(k < i.size() && i[k][0] <= e){
                e = max(e, i[k][1]);
                k++;
            }
            ans.push_back(vector<int> {s, e});
        }
        
        return ans;
    }
};