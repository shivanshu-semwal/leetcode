class Solution {
public:
    vector<vector<int>> insert(
        vector<vector<int>>& intervals, 
        vector<int>& t
    ) {
        int n = intervals.size();
        vector<vector<int>> ans ;
        int i=0;
        for(i=0;i<intervals.size();i++){
           if(intervals[i][1] < t[0]) ans.push_back(intervals[i]);
           else break;
        }
        if(i==n){
            ans.push_back(t);
            return ans;
        }
        
        vector<int> newi(2, 0);
        if(intervals[i][0] > t[1]){
            newi = t;
            ans.push_back(newi);
        } else{
            newi[0] = min(intervals[i][0], t[0]);
            newi[1] = max(intervals[i][1], t[1]);
            for(i=i+1;i<n;i++){
                if(intervals[i][0] <= newi[1]){
                    newi[1] = max(newi[1], intervals[i][1]);
                } else {
                    ans.push_back(newi);
                    break;
                }
            }
            if(i==n) ans.push_back(newi);
        }
        for(;i<n;i++) ans.push_back(intervals[i]);
        return ans;
    }
};