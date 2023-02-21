class Solution {
public:
    bool isValid(vector<vector<char>>& board, int x, int y, char val){
        int i, j;
        int s=x/3;
        int e=y/3;
        for(i=s*3;i<s*3+3;i++){
            for(j=e*3;j<e*3+3;j++){
                if(board[i][j]==val){
                    return false;
                }
            }
        }   
        for(i=0;i<9;i++) if(board[x][i]==val) return false;
        for(i=0;i<9;i++) if(board[i][y]==val) return false;
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int x, int y) {
        if(y==9 && x==9) return true;       
        for(int i=x;i<9;i++){
            int y0 = (i==x)?y:0;
            for(int j=y0;j<9;j++){
                if(board[i][j] == '.'){
                    for(int k=1;k<=9;k++){
                        if(isValid(board, i, j, k+'0')){
                            board[i][j] = k+'0';
                            if(j+1==9){
                                if(solve(board, i+1, 0)) return true;
                                else board[i][j] = '.';
                            } else {
                                if(solve(board, i, j+1)){
                                    return true;
                                }
                                else board[i][j] = '.';
                            }   
                        }
                    }
                    return false;  
                }    
            }   
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool s = solve(board, 0, 0);
    }
};
