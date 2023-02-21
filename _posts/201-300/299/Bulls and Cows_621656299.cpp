class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int bull = 0;
        int cows = 0;
        
        vector<int> digits(10, 0);
        vector<int> digits1(10, 0);
        
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i])
                bull++;
            else {
                digits[secret[i]-'0']++;
                digits1[guess[i]-'0']++;
            }
        }
        
        for(int i=0;i<10;i++){
            cows += (digits1[i] > digits[i])?digits[i]:digits1[i];
        }
        
        string ans = to_string(bull) + "A" + to_string(cows) + "B";
        return ans;
        
    }
};
