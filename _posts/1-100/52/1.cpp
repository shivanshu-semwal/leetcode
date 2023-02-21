class Solution {
public:
    // n <= 9
    int ans;
    int n;
    vector<int> rows;
    vector<int> col;
    vector<int> diagonaly;
    vector<int> diagonalx;
    
    void solve(int i, int j, int t){
        i += j/n;
        j %= n;
        if(i==n){ if(t == 0) ans++; return; }
        if(rows[i] || col[j] || diagonalx[i+j] || diagonaly[i+n-j]){
            solve(i, j+1, t);
        } else {
            rows[i] = col[j] = diagonalx[i+j] = diagonaly[i+n-j] = 1;
            solve(i, j+1, t-1);
            rows[i] = col[j] = diagonalx[i+j] = diagonaly[i+n-j] = 0;
            solve(i, j+1, t);
        }
    }
    
    int totalNQueens(int nn) {
        n = nn;
        rows = vector<int>(n, 0);
        col = vector<int>(n, 0);
        diagonaly = vector<int>(2*n+1, 0);
        diagonalx = vector<int>(2*n+1, 0);
        
        ans=0;
        solve(0, 0, n);
        
        return ans;
    }
};