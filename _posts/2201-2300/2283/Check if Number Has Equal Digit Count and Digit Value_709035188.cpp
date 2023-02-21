class Solution {
public:
    bool digitCount(string num) {
        int count[10];
        int n = num.length();
        memset(count, 0, sizeof count);
        for(int i=0;i<n;i++) count[num[i]-'0']++;
        
        for(int i=0;i<n;i++){
            if(num[i]-'0' != count[i]) return false;
        }
        
        return true;
    }
};
