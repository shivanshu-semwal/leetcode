class Solution {
public:
    string truncateSentence(string s, int k) {
        s = s + " ";
        int i=0, count = 0, point=0;
        for(i=0;count<k && i < s.length();i++){
            if(s[i] == ' '){
                count++;
                point = i;
            }
        }
        string ans = s.substr(0, point);
        return ans;
    }
    
};
