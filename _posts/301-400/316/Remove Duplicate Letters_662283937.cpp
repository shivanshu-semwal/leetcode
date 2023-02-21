class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        int c[27] = {0};
        for(int i=0;i<n;i++) c[s[i] - 'a']++;
        
        stack<char> ans;
        bool taken[27] = {false};
        for(int i=0;i<n;i++){
            if(taken[s[i] - 'a']){
                c[s[i]-'a']--;
                continue;
            }
            int count = c[s[i] - 'a'];
            bool dup = (count > 1);
            char current = s[i];
            //cout << current << " " << dup << endl;   
            while(!ans.empty()){
                if(c[ans.top() - 'a'] != 0){
                    if(ans.top() > current){
                        taken[ans.top() - 'a'] = false;
                        ans.pop();
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
            ans.push(current);
            taken[s[i]-'a'] = true;
            c[s[i]-'a']--;
        }
        string temp = "";
        while(!ans.empty()){
            temp = ans.top() + temp;
            ans.pop();
        }
        return temp;
    }
};
