// 

class Solution {
public:
    bool validateStackSequences(vector<int>& push, vector<int>& pop) {
        int n = pop.size();
        
        unordered_map<int, int> m;
        for(int i=0;i<n;i++) m[push[i]] = i;
        
        vector<bool> visit(n, false);
        int p = -1;
        for(int i=0;i<n;i++){
            int j = m[pop[i]];
            visit[j] = true;
            if(p == -1){
                p = j - 1;
            } else {
                if(j==p) p = p-1;
                else if(j > p) p=j-1;
                else return false;
            }           
            while(p >= 0 && visit[p]) p--;
        }
        
        return true;
    }
};
