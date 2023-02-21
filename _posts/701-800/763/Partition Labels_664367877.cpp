class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int, vector<int>> m;
        for(int i=0;i<s.length();i++){
            if (m.find(s[i])==m.end()){
                m[s[i]] = vector<int> {i};
            } else{
                m[s[i]].push_back(i);
            }
        }
        
        vector<int> ans;
        
        for(int i=0;i<s.length();){
            
            int start = i+1;
            
            if(m[s[i]].size() == 1){
                ans.push_back(1);
                i++;
            } else {
                int n = m[s[i]].size();
                int end = m[s[i]][n-1];
                    
                for(int j=start;j<end;j++){
                    int t = m[s[j]].size();
                    if(end < m[s[j]][t-1]){
                        end = m[s[j]][t-1];
                    }
                }
                ans.push_back(end - start + 2);
                i = end+1;
            }
        }
        return ans;
    }
};
