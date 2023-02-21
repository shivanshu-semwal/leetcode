class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> p;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') p.push(-1);
            else{ // ')'
                int score = 0;
                while(p.top() != -1){
                    score += p.top();
                    p.pop();
                }
                p.pop();
                if(score==0) p.push(1);
                else p.push(2 * score);
            }
        }
        int ans = 0;
        while(!p.empty()){
            ans += p.top();
            p.pop();
        }
        return ans;
    }
};
