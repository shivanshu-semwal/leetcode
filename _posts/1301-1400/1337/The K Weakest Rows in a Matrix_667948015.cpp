class comp {
public:
    bool operator()(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b) {
        int aa = lower_bound(a.second.rbegin(), a.second.rend(), 1) - a.second.rbegin();
        int bb = lower_bound(b.second.rbegin(), b.second.rend(), 1) - b.second.rbegin();
        aa = a.second.size() - aa;
        bb = b.second.size() - bb;
        if (aa == bb) return a.first > b.first;
        else return aa > bb;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int, vector<int>>> x;
        x.reserve(mat.size());
        for(int i=0;i<mat.size();i++) x.push_back({i, mat[i]});
        
        priority_queue < 
            pair<int, vector<int>>, 
            vector<pair<int, vector<int>>>, 
            comp
        > pq(x.cbegin(), x.cend());
        
        vector<int> ans;
        ans.reserve(k);
        
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        return ans;
    }
};
