long mod = 1000000007;
class Solution {
public:
    int knightDialer(int n) {
        vector<vector<long>> a = {{1,1,1}, {1,1,1}, {1,1,1}, {0,1,0}};
        // cout << mod;
        int dx[] = {+2, +2, -2, -2, +1, -1, -1, +1};
        int dy[] = {+1, -1, -1, +1, +2, +2, -2, -2};
        
        for (int i=2;i<=n;i++){
            vector<vector<long>> b = {{0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}};
            
            for(int j=0;j<4;j++){
                for(int k=0;k<3;k++){
                    if(j==3 && k==0) continue;
                    if(j==3 && k==2) continue;
                    for(int m=0;m<8;m++){
                        int nj = j + dx[m], nk = k + dy[m];
                        if(nj < 0 || nk < 0 || nj >= 4 || nk >= 3) continue;
                        b[j][k] = (b[j][k] + a[nj][nk]) % 1000000007L;
                        // if(b[j][k] > mod) b[j][k] %= mod;
                    }
                    
                }
            }
            
            swap(a, b);
        }
        long ans = 0;
        for(int i=0;i<4;i++) for(int j=0;j<3;j++) ans = (ans + a[i][j]) % 1000000007L;
        
        return ans;
    }
};
