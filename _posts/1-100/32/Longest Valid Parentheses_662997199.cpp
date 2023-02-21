class Solution {
public:
    int longestValidParentheses(string s) {
        if(s=="") return 0;
        int left=0, right=0;
        int n = s.length();
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(') left++;
            else right++;
            
            if(left==right) ans = max(2*left, ans);
            
            if(left < right) {
                left = 0;
                right = 0;
            }
        }
        left = 0;
        right = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == ')') right++;
            else left++;
            
            if(left==right) ans = max(2*right, ans);
            
            if(left > right) {
                left = 0;
                right = 0;
            }
        }
        
        return ans;
    }
};
