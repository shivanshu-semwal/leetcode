class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a==0 ? 1: a;
        return gcd(b, a%b);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        int n = points.size();
        for(int i=0;i<n;i++){
            // cout << "point: " << points[i][0] << " , " << points[i][1] << endl;
            unordered_map<int, unordered_map<int, int>> m;
            for(int j=i+1;j<n;j++){
                // cout << "xx: "<< points[j][0] << " , " << points[j][1] << endl;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                if(dx < 0){
                    dy = -dy;
                    dx = -dx;
                }
                
                cout << dx << " " << dy << endl;
                int t = gcd(dx, dy);
                dx /= t;
                dy /= t;
                
                if(m.find(dx) == m.end()) m[dx] = unordered_map<int, int>();
                if(m[dx].find(dy) == m[dx].end()) m[dx][dy] = 1;
                else m[dx][dy]++;
                
                ans = max(ans, m[dx][dy] + 1);
            }
        }
        
        return ans;
    }
};
