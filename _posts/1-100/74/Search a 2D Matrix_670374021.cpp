class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int t) {
        int l = 0, r = m.size() * m.back().size() - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(m[mid / m.back().size()][mid % m.back().size()] == t) return true;
            else if(m[mid / m.back().size()][mid % m.back().size()] < t) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
