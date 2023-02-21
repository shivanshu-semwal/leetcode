class Solution {
public:
    
    vector<vector<int>> cache;
    
    int dp(int node, int mask, vector<vector<int>>& graph){
        
        if(cache[node][mask] != -1) return cache[node][mask];
        
        if((mask & (mask - 1)) == 0) return 0; // all node visited
        
        cache[node][mask] = INT_MAX - 1;
   
        for(int neig: graph[node]){
            
            if((mask & (1 << neig)) != 0){
            
                int m = dp(neig, mask, graph);
                
                m = min(m, dp(neig, mask ^ (1 << node), graph));
                
                cache[node][mask] = min(cache[node][mask], 1 + m);
            }
        }
        return cache[node][mask];
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        int endmask = (1 << n) - 1;
        
        cache = vector<vector<int>> (n+10, vector<int> (endmask+10, -1));
        
        int m = INT_MAX;
        
        for(int i=0;i<n;i++){
            m = min(m, dp(i, endmask, graph));   
        }
        
        return m;
    }
};
