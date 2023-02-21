// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> a(n, vector<int> (n, 0));
        
        int c=1;
        for(int i=0;i<(n+1)/2;i++){
            for(int k=i;k<=n-i-1;k++){
                a[i][k] = c++;
            }
            for(int k=i+1;k<=n-i-1;k++){
                a[k][n-i-1] = c++;
            }
            for(int k=n-i-2;k>=i;k--){
                a[n-i-1][k] = c++;
            }
            for(int k=n-i-2;k>=i+1;k--){
                a[k][i] = c++;
            }
        }
        
        return a;
    }
};