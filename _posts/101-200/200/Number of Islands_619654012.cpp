class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        // visited array
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int count = 0;

        for (int i = 0; i < n; i++) { //row

            for (int j = 0; j < m; j++) { //column
                // breadth first search
                // cout << "i: " << i << " j: " << j << "\n";
                if (visited[i][j] == false && grid[i][j] == '1') {
                    count++;
                    // int c=0;
                    queue<pair<int, int>> q;
                    q.push({i, j}); // {row, column}
                    while (!q.empty()) {
                        // c++;
                        pair<int, int> t = q.front();
                        q.pop();

                        int ii = t.first;  // row
                        int jj = t.second; // column

                        if (visited[ii][jj] == false) {
                            visited[ii][jj] = true;
                            // cout << "("<< ii << "," << jj << ")->";
                            if (jj + 1 < m) {
                                // move right
                                if (grid[ii][jj + 1] == '1' && visited[ii][jj + 1] == false) {
                                    q.push({ii, jj + 1});
                                }
                            }
                            if (jj - 1 >= 0) {
                                //move left
                                if (grid[ii][jj - 1] == '1' && visited[ii][jj - 1] == false) {
                                    q.push({ii, jj - 1});
                                }
                            }
                            if (ii + 1 < n) {
                                //move down
                                if (grid[ii + 1][jj] == '1' && visited[ii + 1][jj] == false) {
                                    q.push({ii + 1, jj});
                                }
                            }
                            if (ii - 1 >= 0) {
                                // move up
                                if (grid[ii - 1][jj] == '1' && visited[ii - 1][jj] == false) {
                                    q.push({ii - 1, jj});
                                }
                            }
                        }
                    }
                }
            }
        }

        // no of islands
        return count;
    }
};

