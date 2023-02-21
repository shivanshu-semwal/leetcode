bool comp(const vector<int> &a,const vector<int> &b){
    return (a[0]-a[1]) < (b[0]-b[1]);
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        sort(costs.begin(), costs.end(), comp);
        int sum=0;
        for(int i=0;i<n;i++) sum += costs[i][0];
        for(int i=n;i<2*n;i++) sum += costs[i][1];
        return sum;
    }
};
