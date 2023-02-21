class Solution {
public:
    
    void kruskal(
        vector<vector< pair<int, int> >> &adj,
        int k,
        int n,
        vector<int> &time
    ){
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        
        pq.push({0, k});
        time[k] = 0;
        while(!pq.empty()){
            int cNodeTime = pq.top().first;
            int cNode = pq.top().second;
            pq.pop();
            
            if(cNodeTime > time[cNode]) continue;
            for(pair<int, int> edge: adj[cNode]){
                int t = edge.first;
                int nNode = edge.second;
                
                if(time[nNode] > cNodeTime + t){
                    time[nNode] = cNodeTime + t;
                    pq.push({time[nNode], nNode});
                }
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector< pair<int, int> >> adj(n+1, vector<pair<int, int>>());
        for(int i=0;i<times.size(); i++){
            int source = times[i][0];
            int dest = times[i][1];
            int weight = times[i][2];
            adj[source].push_back({weight, dest});
        }
        
        vector<int> time(n+1, INT_MAX);
        
        kruskal(adj, k, n, time);
        int ans = INT_MIN;
        for(int i=1;i<=n;i++) ans = max(ans, time[i]);
        return ans == INT_MAX ? -1: ans;
        
    }
};
