class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c = 0;
                int x[] = {-1, -1, -1, +0, +0, +1, +1, +1};
                int y[] = {-1, +0, +1, -1, +1, -1, +0, +1};
                for(int k=0;k<8;k++){
                    int ni = i+x[k], nj = j+y[k];
                    if(0<=ni && ni < n && 0<=nj && nj < m){
                        if(board[ni][nj] & 1) c++;
                    }
                }
                if(board[i][j]){
                    if(c==2 || c==3) board[i][j] ^= 2;
                } else {
                    if(c==3) board[i][j] ^= 2;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = board[i][j] >> 1;
            }
        } 
    }
};

/*
i-1,j-1 i-1,j+0 i-1,j+1
i+0,j-1 i+0,j+0 i+0,j+1
i+1,j-1 i+1,j+0 i+1,j+1
*/
