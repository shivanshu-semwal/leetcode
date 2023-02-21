class Solution {
public:
    vector<vector<string>> sol;
    vector<string> chess;
    void countt(int n,
           vector<int> &col,
           vector<int> &diag1,
           vector<int> &diag2,
           int row) {
        if (row == n) {
            sol.push_back(chess);
            return;
        }
        /* select column */
        for (int x = 0; x < n; x++) {
            if (col[x] || diag1[x + row] || diag2[n - 1 + x - row]) {
                continue;
            }
            col[x] = diag1[x + row] = diag2[n - 1 + x - row] = 1;
            chess[row][x] = 'Q';
            countt(n, col, diag1, diag2, row + 1);
            chess[row][x] = '.';
            col[x] = diag1[x + row] = diag2[n - 1 + x - row] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        chess = vector<string>(n, string(n,'.'));
        vector<int> col(n, 0);
        vector<int> diag1(2 * n - 1, 0);
        vector<int> diag2(2 * n - 1, 0);
        countt(n, col, diag1, diag2, 0);
        return sol;
    }
};
