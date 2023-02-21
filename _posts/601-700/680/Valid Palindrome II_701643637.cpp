class Solution {
public:
    bool isPalindrome(string s){
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-i-1]) return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        for(int i=0; i<s.length()/2;i++){
            if(s[i]!=s[s.length()-i-1]){
                // cout << s.substr(i+1, s.length()-i-1 - i-1 + 1) << " " <<
                //         s.substr(i, s.length()-i-2 - i + 1) << endl;
                return isPalindrome(s.substr(i+1, s.length()-i-1 - i-1 + 1)) ||
                       isPalindrome(s.substr(i, s.length()-i-2 - i + 1));
            }
        }
        return true;
    }
};
