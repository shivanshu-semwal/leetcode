class cmp {
public:
    bool operator()(const array<int, 3> &a, const array<int, 3> &b){ return a[0] > b[0]; }
};

class Solution {
public:
  int rows, cols;
    vector<pair<int, int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    priority_queue<array<int, 3>, vector<array<int, 3>>, cmp> pq;
    
    // void print(vector<vector<int>>& grid){
    //     for(auto i:grid){
    //         for(auto j:i){
    //             cout<<j<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;cout<<endl;
    // }
    
    
    inline bool isValid(int x, int y){
        return (x>=0 && x<rows && y>=0 && y<cols);
    }
    int swimInWater(vector<vector<int>>& grid) {
        
        rows = grid.size();
        cols = grid[0].size();
        
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            array<int, 3> top = pq.top();
            pq.pop();
            
            for(auto i:dirs){
                pair<int, int> neighbour = {i.first + top[1], i.second + top[2]};
                
                if(!isValid(neighbour.first, neighbour.second)) continue;
                
                if(grid[neighbour.first][neighbour.second] == -1) continue;
                
                grid[neighbour.first][neighbour.second] = 
                    max(grid[neighbour.first][neighbour.second], top[0]);
                
                pq.push({
                    grid[neighbour.first][neighbour.second], 
                    neighbour.first, neighbour.second
                });
            }
            if(top[1] == rows-1 && top[2] == cols-1) return grid.back().back();
            grid[top[1]][top[2]] = -1;
            // print(grid);
        }
        return grid.back().back();
    }
};
