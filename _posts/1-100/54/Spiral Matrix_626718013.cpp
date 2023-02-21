class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int size = matrix[0].size() * matrix.size();
        vector<int> sol(size);
        int l = 0, r = matrix[0].size() - 1, t=0, b=matrix.size() - 1;
        int c=0;
        while(c < size){
            for(int i=l;i<=r;i++) sol[c++] = matrix[t][i]; t++; if(c == size) return sol;
            for(int i=t;i<=b;i++) sol[c++] = matrix[i][r]; r--; if(c == size) return sol;
            for(int i=r;i>=l;i--) sol[c++] = matrix[b][i]; b--; if(c == size) return sol;
            for(int i=b;i>=t;i--) sol[c++] = matrix[i][l]; l++; if(c == size) return sol;
        }
        return sol;
    }
};
