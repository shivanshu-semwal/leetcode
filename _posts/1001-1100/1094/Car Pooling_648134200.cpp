bool comp(vector<int> a, vector<int> b){
    return (a[1] < b[1] || (a[1]==b[1] && a[2] < b[2]));
}
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), comp);
        int cur = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<trips.size();i++){
            while(!pq.empty() && pq.top().first <= trips[i][1]){
                cur -= pq.top().second;
                pq.pop();
            }
           
            pq.push({trips[i][2], trips[i][0]});
            cur += trips[i][0];
            
            if(cur > capacity) return false;
        }
        return true;
    }
};
