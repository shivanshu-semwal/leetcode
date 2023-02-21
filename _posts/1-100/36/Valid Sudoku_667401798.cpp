class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y){
        for(int i=(x/3)*3;i<(x/3)*3+3;i++){
            for(int j=(y/3)*3;j<(y/3)*3+3;j++){
                if(i==x&&j==y) continue;
                if(board[i][j] == board[x][y]) return false;
            }
        }
        for(int i=0;i<9;i++){
            if(i==x) continue;
            if(board[i][y] == board[x][y]) return false;
        }
        for(int i=0;i<9;i++){
            if(i==y) continue;
            if(board[x][i] == board[x][y]) return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.') if(!isValid(board, i, j)) return false;
            }
        }
        return true;
    }
};
