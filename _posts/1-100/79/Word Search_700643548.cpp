class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string &word, int pt, int x, int y){
        if(pt == word.size()) return true;
        
        if(x < 0 || x >= board.size() || 
           y < 0 || y >= board[0].size() || 
           board[x][y] != word[pt])
            
            return false;
        
        board[x][y] = '0';
        bool ans = dfs(board, word, pt+1, x+1, y) ||
                   dfs(board, word, pt+1, x, y+1) ||
                   dfs(board, word, pt+1, x-1, y) ||
                   dfs(board, word, pt+1, x, y-1);
        board[x][y] = word[pt];
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board, word, 0, i, j)) return true;
            }
        }

        return false;
    }
};
