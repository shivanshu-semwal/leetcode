class comp {
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second == b.second) return a.first > b.first;
        else return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int, int>> x;
        x.reserve(mat.size());
        for(int i=0;i<mat.size();i++){
            int t = mat[i].size() - 
            (lower_bound(mat[i].rbegin(), mat[i].rend(), 1) - mat[i].rbegin());
            
            x.push_back({i, t});
        }
        priority_queue < 
            pair<int, int>, 
            vector<pair<int, int>>, 
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
