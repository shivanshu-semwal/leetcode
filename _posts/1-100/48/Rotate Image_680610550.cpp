typedef pair<int, int> pii;
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        pii tl, tr, bl, br;
        int n = m.size() - 1;
        for(int k=0;k<m.size()/2;k++){
            tl = {k, k};
            tr = {k, n-k};
            br = {n-k, n-k};
            bl = {n-k, k};
            for(int i=0;i<tr.second-tl.first;i++){
                // cout << m[tl.first][tl.second + i] << " "
                //         << m[tr.first + i][tr.second] << " " 
                //         << m[br.first][br.second - i] << " "
                //         << m[bl.first - i][bl.second] << endl;
                swap(m[tl.first][tl.second + i], m[tr.first + i][tr.second]);
                swap(m[tl.first][tl.second + i], m[br.first][br.second - i]);
                swap(m[tl.first][tl.second + i], m[bl.first - i][bl.second]);
            }
        }    
    }
};
