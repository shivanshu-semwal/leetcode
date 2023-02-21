class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int x = ans.size() - 1;
            if(intervals[i][0] <= ans[x][1]){
                vector<int> temp(2, 0);
                temp[0] = ans[x][0];
                temp[1] = max(intervals[i][1], ans[x][1]) ;
                ans[x] = temp;
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
