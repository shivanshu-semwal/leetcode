class Solution {
public:
    unordered_map<string, int> m;
    
    inline int noWords(string &s){
        int ans = 0;
        for(auto i: s) if(i==' ') ans++;
        return ans+1;
    }
    
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        
        int ans = 0;
        int ans_l = 0;
        
        for(int i=0;i<n;i++){
            int no = noWords(messages[i]);
            if(m.find(senders[i]) == m.end()) m[senders[i]] = no;
            else{
                no += m[senders[i]];
                m[senders[i]] = no;
            }
            
            if(ans_l < no){
                ans_l = no;
                ans = i;
            }
            else if(ans_l == no){
                if(senders[i] > senders[ans]){
                    ans = i;
                }
            }
        }
        
        return senders[ans];
    }
};
