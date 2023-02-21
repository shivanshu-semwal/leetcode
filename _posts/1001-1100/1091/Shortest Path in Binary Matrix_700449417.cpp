class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> dx = {-1, +0, +1, -1, +1, -1, +0, +1};
        vector<int> dy = {-1, -1, -1, +0, +0, +1, +1, +1};
        
        queue<vector<int>> q;
        
        if(grid[0][0] == 1) return -1;
        else q.push({0, 0, 0});
        
        while(!q.empty()){
            int y = q.front()[0];
            int x = q.front()[1];
            int w = q.front()[2];
            q.pop();
            // cout << y << " " << x << endl;
            grid[y][x] = -1;
            if(y==n-1 && x == m-1) return w+1;
            
            for(int i=0;i<dx.size();i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n) continue;
                if(nx < 0 || nx >= m) continue;
                if(grid[ny][nx] == -1 || grid[ny][nx] == 1) continue;
                q.push({ny, nx, w+1});
                grid[ny][nx] = -1;
            }
        }
        
        return -1;
    }
};
